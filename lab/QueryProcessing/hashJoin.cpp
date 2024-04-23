//
// Created by zl on 2023/12/12.
//

#include <iostream>
#include <unistd.h>
#include "join.h"
#include "file.h"
#include "blkio.h"

using namespace std;

int hashJoin(Buffer *buf)
{
	/**
	 * select * from R, S where R.A = S.C;
	 */
	// get a block for write
	unsigned char *blk;

	// hash R
	pushHashToWrite(buf, NULL, HASH_R_ADDR, true);
	for (int i = 0; i < R_BLK_NUM; i++) { // for each blk of R
		if ((blk = readBlockFromDisk(R_ADDR + i, buf)) == NULL) {
			perror("Reading Block Failed!\n");
			return -1;
		}
		Relation R[TUPLE_PER_BLK];
		readTuplesFromBlock(blk, R);
		for (int j = 0; j < TUPLE_PER_BLK; j++) {
			pushHashToWrite(buf, &R[j], HASH_R_ADDR);
		}
		freeBlockInBuffer(blk, buf);
	}
	pushHashToWrite(buf, NULL, HASH_R_ADDR, false, true);
	cout << "numIO after hash R: " << buf->numIO << endl;

	// hash S
	pushHashToWrite(buf, NULL, HASH_S_ADDR, true);
	for (int i = 0; i < S_BLK_NUM; i++) { // for each blk of S
		if ((blk = readBlockFromDisk(S_ADDR + i, buf)) == NULL) {
			perror("Reading Block Failed!\n");
			return -1;
		}
		Relation S[TUPLE_PER_BLK];
		readTuplesFromBlock(blk, S);
		for (int j = 0; j < TUPLE_PER_BLK; j++) {
			pushHashToWrite(buf, &S[j], HASH_S_ADDR);
		}
		freeBlockInBuffer(blk, buf);
	}
	pushHashToWrite(buf, NULL, HASH_S_ADDR, false, true);
	cout << "numIO after hash S: " << buf->numIO << endl;

	// join
	for (int key = 0; key < BUCKET_NUM; key++) {
		// get a block for write
		pushToWrite(buf, NULL, 0, HJ_RET_ADDR, true);
		int bucketBlkNumR = 0;
		unsigned char *blkR[BUCKET_NUM];
		char filename[40];
		// build
		while (true) {
			sprintf(filename, "%d.blk", HASH_R_ADDR + key*100 + bucketBlkNumR);
			if (access(filename, F_OK) == -1) { break; } // file does not exist
			blkR[bucketBlkNumR++] = readBlockFromDisk(HASH_R_ADDR + key*100 + bucketBlkNumR, buf);
		}
		int RNum = 0;
		Relation R[HASH_PER_BLK*bucketBlkNumR];
		for (int i = 0; i < bucketBlkNumR; i++) {
			int blkRNum = readHashFromBlock(blkR[i], R + RNum);
			RNum += blkRNum;
		}
//		cout << "RNum: " << RNum << endl;
		// probe
		int bucketBlkNumS = 0;
		unsigned char *blkS;
		while (true) {
			sprintf(filename, "%d.blk", HASH_S_ADDR + key*100 + bucketBlkNumS);
			if (access(filename, F_OK) == -1) { break; } // file does not exist
			blkS = readBlockFromDisk(HASH_S_ADDR + key*100 + bucketBlkNumS, buf);
			bucketBlkNumS++;
			Relation S[HASH_PER_BLK];
			int blkSNum = readHashFromBlock(blkS, S);
			for (int i = 0; i < blkSNum; i++) {
				for (int j = 0; j < RNum; j++) {
					if (R[j].attr1 == S[i].attr1) {
						output(buf, HJ_RET_ADDR, R[j].attr1, R[j].attr2, S[i].attr2);
					}
				}
			}
			freeBlockInBuffer(blkS, buf);
		}
		for (int i = 0; i < bucketBlkNumR; i++) {
			freeBlockInBuffer(blkR[i], buf);
		}
	}
	pushToWrite(buf, NULL, 0, HJ_RET_ADDR, false, true);
	cout << "total numIO: " << buf->numIO << endl;
	return 0;
}