//
// Created by zl on 2023/12/11.
//

#include <iostream>
#include "join.h"
#include "file.h"
#include "blkio.h"
#include "mergeSort.h"

using namespace std;

int sortMergeJoin(Buffer *buf)
{
	/**
	 * select * from R, S where R.A = S.C;
	 */
	mergeSort(buf, SORT_R);
	mergeSort(buf, SORT_S);

	// do join based on sorted R and S
	// get a block for write
	pushToWrite(buf, NULL, 0, SMJ_RET_ADDR, true);

	// read the first blk of each segment
	unsigned char *blkR, *blkS;
	if ((blkR = readBlockFromDisk(MERGE_R_RET_ADDR, buf)) == NULL) {
		perror("Reading Block Failed!\n");
		return -1;
	}
	if ((blkS = readBlockFromDisk(MERGE_S_RET_ADDR, buf)) == NULL) {
		perror("Reading Block Failed!\n");
		return -1;
	}
	Relation R[TUPLE_PER_BLK], S[TUPLE_PER_BLK];
	readTuplesFromBlock(blkR, R);
	readTuplesFromBlock(blkS, S);
	int curR = 0, curS = 0;
	int blkCurR = 0, blkCurS = 0;
	while (true) {
		int target = max(R[blkCurR].attr1, S[blkCurS].attr1);
		// only zero or one of the while loop will be executed
		while (R[blkCurR].attr1 < target) {
			blkCurR++;
			if (blkCurR == TUPLE_PER_BLK) {
				curR++;
				blkCurR = 0;
				freeBlockInBuffer(blkR, buf);
				if (curR != R_BLK_NUM) {
					// read a new blk from R
					if ((blkR = readBlockFromDisk(MERGE_R_RET_ADDR + curR, buf)) == NULL) {
						perror("Reading Block Failed!\n");
						return -1;
					}
					readTuplesFromBlock(blkR, R);
				} else {
					cout << "total numIO: " << buf->numIO << endl;
					return 0; // clear to return here
				}
			}
		}
		while (S[blkCurS].attr1 < target) {
			blkCurS++;
			if (blkCurS == TUPLE_PER_BLK) {
				curS++;
				blkCurS = 0;
				freeBlockInBuffer(blkS, buf);
				if (curS != S_BLK_NUM) {
					// read a new blk from S
					if ((blkS = readBlockFromDisk(MERGE_S_RET_ADDR + curS, buf)) == NULL) {
						perror("Reading Block Failed!\n");
						return -1;
					}
					readTuplesFromBlock(blkS, S);
				} else {
					cout << "total numIO: " << buf->numIO << endl;
					return 0; // clear to return here
				}
			}
		}
		// if R and S have the same attr A/C, do join
		if (R[blkCurR].attr1 == target && S[blkCurS].attr1 == target) {
			int tmpBlkCur, tmpCur;
			while (S[blkCurS].attr1 == target) {
				tmpBlkCur = blkCurR;
				tmpCur = curR;
				unsigned char *tmpBlk = NULL;
				while (R[tmpBlkCur].attr1 == target) {
					output(buf, SMJ_RET_ADDR, R[tmpBlkCur].attr1, R[tmpBlkCur].attr2, S[blkCurS].attr2);
					tmpBlkCur++;
					if (tmpBlkCur == TUPLE_PER_BLK) {
						tmpCur++;
						tmpBlkCur = 0;
						if (tmpCur != R_BLK_NUM) {
							// read a extra blk from R
							if ((tmpBlk = readBlockFromDisk(MERGE_R_RET_ADDR + tmpCur, buf)) == NULL) {
								perror("Reading Block Failed!\n");
								return -1;
							}
							readTuplesFromBlock(tmpBlk, R);
						}
					}
				}
				if (tmpBlk != NULL)
					freeBlockInBuffer(tmpBlk, buf);
				readTuplesFromBlock(blkR, R); // reset the R
				blkCurS++;
				if (blkCurS == TUPLE_PER_BLK) {
					curS++;
					blkCurS = 0;
					freeBlockInBuffer(blkS, buf);
					if (curS != S_BLK_NUM) {
						// read a new blk from S
						if ((blkS = readBlockFromDisk(MERGE_S_RET_ADDR + curS, buf)) == NULL) {
							perror("Reading Block Failed!\n");
							return -1;
						}
						readTuplesFromBlock(blkS, S);
					} else {
						cout << "total numIO: " << buf->numIO << endl;
						return 0; // clear to return here}
					}
				}
			}
			// relax curR and blkCurR
			blkCurR = tmpBlkCur;
			if (curR != tmpCur) {
				curR = tmpCur;
				freeBlockInBuffer(blkR, buf);
				if (curR == R_BLK_NUM) {
					cout << "total numIO: " << buf->numIO << endl;
					return 0; // clear to return here
				}
				if ((blkR = readBlockFromDisk(MERGE_R_RET_ADDR + curR, buf)) == NULL) {
					perror("Reading Block Failed!\n");
					return -1;
				}
				readTuplesFromBlock(blkR, R);
			}
		}
	}
}