//
// Created by zl on 2023/12/11.
//

#include <string.h>
#include <iostream>
#include "blkio.h"
#include "file.h"

void pushToWrite(Buffer *buf, unsigned char *source, size_t size, unsigned int addr, bool reset, bool push)
{
	// get a blk in buffer for writing the results
	static unsigned char *writeBlk = getNewBlockInBuffer(buf);
	static int writeCur = 0;
	static int writeBlkNum = 0;

	// reinitialize the writeBlk and other STATIC variables
	if (reset) {
		// write the remaining tuples to disk
		if (buf->numFreeBlk < 8)
			freeBlockInBuffer(writeBlk, buf);
		writeBlk = getNewBlockInBuffer(buf);
		memset(writeBlk, 0, BLK_SIZE);
		writeCur = 0;
		writeBlkNum = 0;
		return;
	}

	// push the writeBlk to disk right now
	if (push) {
		if (writeCur != 0) {
			writeBlockToDisk(writeBlk, addr + writeBlkNum, buf);
			writeBlkNum++;
			writeBlk = getNewBlockInBuffer(buf);
			memset(writeBlk, 0, BLK_SIZE);
			writeCur = 0;
		}
		return;
	}

	// if the remaining space in writeBlk is not enough for the tuple,
	// write the current block to disk, and get a new block
	if (writeCur + size > BLK_SIZE - PTR_SIZE) {
		writeBlockToDisk(writeBlk, addr + writeBlkNum, buf);
		writeBlkNum++;
		writeBlk = getNewBlockInBuffer(buf);
		memset(writeBlk, 0, BLK_SIZE);
		writeCur = 0;
	}

	memcpy(writeBlk + writeCur, source, size);
	writeCur += size;
}

void readTuplesFromBlock(unsigned char *blk, Relation *R)
{
	for (int i = 0; i < TUPLE_PER_BLK; i++) {
		memcpy(&R[i], blk + i*8, 8);
	}
}

void output(Buffer *buf, unsigned int addr, int attr1, int attr2, int attr3)
{
	std::cout << attr1 << "\t" << attr2 << "\t" << attr3 << std::endl;
	Relation3 R3;
	R3.attr1 = attr1;
	R3.attr2 = attr2;
	R3.attr3 = attr3;
	pushToWrite(buf, (unsigned char *)&R3, 12, addr);
}

void pushHashToWrite(Buffer *buf, Relation *R, unsigned int addr, bool reset, bool push)
{
	static unsigned char *bucketBlk[BUCKET_NUM];
	static int bucketCur[BUCKET_NUM] = { 0 };
	static int bucketBlkNum[BUCKET_NUM] = { 0 };

	if (reset) {
		for (int i = 0; i < BUCKET_NUM; i++) {
			bucketBlk[i] = getNewBlockInBuffer(buf);
			memset(bucketBlk[i], 0, BLK_SIZE);
			bucketCur[i] = 0;
			bucketBlkNum[i] = 0;
		}
		return;
	}

	if (push) {
		for (int i = 0; i < BUCKET_NUM; i++) {
			if (bucketCur[i] != 0) {
				writeBlockToDisk(bucketBlk[i], addr + i*100 + bucketBlkNum[i], buf);
				bucketBlkNum[i]++;
				bucketBlk[i] = getNewBlockInBuffer(buf);
				memset(bucketBlk[i], 0, BLK_SIZE);
				bucketCur[i] = 0;
			}
		}
		if (buf->numFreeBlk < 8) {
			for (int i = 0; i < BUCKET_NUM; i++) {
				freeBlockInBuffer(bucketBlk[i], buf);
			}
		}
		return;
	}

	unsigned char key = R->attr1%BUCKET_NUM;

	if (bucketCur[key] + 9 > BLK_SIZE - PTR_SIZE) {
		writeBlockToDisk(bucketBlk[key], addr + key*100 + bucketBlkNum[key], buf);
		bucketBlkNum[key]++;
		bucketBlk[key] = getNewBlockInBuffer(buf);
		memset(bucketBlk[key], 0, BLK_SIZE);
		bucketCur[key] = 0;
	}

	memcpy(bucketBlk[key] + bucketCur[key], &key, 1);
	memcpy(bucketBlk[key] + bucketCur[key] + 1, &(R->attr1), 4);
	memcpy(bucketBlk[key] + bucketCur[key] + 5, &(R->attr2), 4);
	bucketCur[key] += 9;

//	std::cout << (int)key << " " << R->attr1 << " " << R->attr2 << std::endl;

}

int readHashFromBlock(unsigned char *blk, Relation *R)
{
	int blkCur = 0;
	while (true) {
		if (blkCur == HASH_PER_BLK || *(blk + 1 + blkCur*9) == 0) {
			break;
		}
		memcpy(&R[blkCur], blk + 1 + blkCur*9, 8);
		blkCur++;
	}
	return blkCur;
}
