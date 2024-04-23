//
// Created by zl on 2023/12/12.
//

#include <iostream>
#include <math.h>
#include "join.h"
#include "file.h"
#include "blkio.h"

using namespace std;

int nestedLoopJoin(Buffer *buf)
{
	/**
	 * select * from R, S where R.A = S.C;
	 */
	// get a block for write
	pushToWrite(buf, NULL, 0, NLJ_RET_ADDR, true);
	int blkNumOuter = buf->numFreeBlk - 1; // aka M-1
	int loopNumOuter = ceil(1.0*R_BLK_NUM/blkNumOuter);
	unsigned char *blkR[blkNumOuter];
	unsigned char *blkS;
	for (int i = 0; i < loopNumOuter; i++) {
		// read M-1 blks of R
		int thisBlkNum = min(blkNumOuter, R_BLK_NUM - i*blkNumOuter);
		for (int j = 0; j < thisBlkNum; j++) {
			if ((blkR[j] = readBlockFromDisk(R_ADDR + i*blkNumOuter + j, buf)) == NULL) {
				perror("Reading Block Failed!\n");
				return -1;
			}
		}
		Relation R[TUPLE_PER_BLK*thisBlkNum];
		for (int j = 0; j < thisBlkNum; j++) {
			readTuplesFromBlock(blkR[j], R + j*TUPLE_PER_BLK);
		}
		// read each blk of S
		for (int j = 0; j < S_BLK_NUM; j++) {
			if ((blkS = readBlockFromDisk(S_ADDR + j, buf)) == NULL) {
				perror("Reading Block Failed!\n");
				return -1;
			}
			Relation S[TUPLE_PER_BLK];
			readTuplesFromBlock(blkS, S);
			// do join
			for (int k = 0; k < TUPLE_PER_BLK; k++) { // for each tuple of S.blk
				for (int l = 0; l < TUPLE_PER_BLK*thisBlkNum; l++) { // for each tuple of R.blk
					if (R[l].attr1 == S[k].attr1) {
						output(buf, NLJ_RET_ADDR, R[l].attr1, R[l].attr2, S[k].attr2);
					}
				}
			}
			freeBlockInBuffer(blkS, buf);
		}
		for (int j = 0; j < thisBlkNum; j++) {
			freeBlockInBuffer(blkR[j], buf);
		}
	}
	pushToWrite(buf, NULL, 0, NLJ_RET_ADDR, false, true);
	cout << "total numIO: " << buf->numIO << endl;
	return 0;
}