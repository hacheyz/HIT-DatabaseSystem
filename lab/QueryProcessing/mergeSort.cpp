//
// Created by zl on 2023/12/11.
//

#include <iostream>
#include <string.h>
#include <algorithm>
#include <cmath>
#include "mergeSort.h"
#include "file.h"
#include "blkio.h"

using namespace std;

int mergeSort(Buffer *buf, bool choice)
{
	// Two-Pass Multi-Way External Merge Sort, comments are for R
	int totalBlkNum = (choice == SORT_R ? R_BLK_NUM : S_BLK_NUM);
	int inAddr = (choice == SORT_R ? R_ADDR : S_ADDR);
	int segAddr = (choice == SORT_R ? MERGE_R_SEG_ADDR : MERGE_S_SEG_ADDR);
	int retAddr = (choice == SORT_R ? MERGE_R_RET_ADDR : MERGE_S_RET_ADDR);

	// step 1: run - create merge segment
	// get a block for write
	pushToWrite(buf, NULL, 0, segAddr, true);
	int segSize = buf->numFreeBlk; // 7, aka M
	unsigned char *blk[segSize]; // -1 for the writeBlk
	int segNum = ceil(1.0*totalBlkNum/segSize); // ceil(16/7) = 3
	int segBlkNum[segNum];
	for (int i = 0; i < segNum; i++) {
		int blkNum = min(segSize, totalBlkNum - i*segSize);
		segBlkNum[i] = blkNum;
		for (int j = 0; j < blkNum; j++) {
			if ((blk[j] = readBlockFromDisk(inAddr + i*segSize + j, buf)) == NULL) {
				perror("Reading Block Failed!\n");
				return -1;
			}
		}
		Relation R[TUPLE_PER_BLK*blkNum];
		for (int j = 0; j < blkNum; j++) {
			readTuplesFromBlock(blk[j], R + j*TUPLE_PER_BLK);
		}
		// sort segment i by R.A
		sort(R, R + TUPLE_PER_BLK*blkNum, [](Relation a, Relation b)
		{ return a.attr1 < b.attr1; });
		// save the result R
		for (int j = 0; j < TUPLE_PER_BLK*blkNum; j++) {
			pushToWrite(buf, (unsigned char *)&R[j], 8, segAddr);
		}
		for (int j = 0; j < blkNum; j++) {
			freeBlockInBuffer(blk[j], buf);
		}
	}
	pushToWrite(buf, NULL, 0, segAddr, false, true);
	cout << "numIO after mergesort.run: " << buf->numIO << endl;

	// step 2: merge
	// get a block for write
	pushToWrite(buf, NULL, 0, retAddr, true);
	// read the first blk of each segment
	int segCur[segNum]; // how many blks have been move to output from segment i
	int segBlkCur[segNum]; // how many tuples have been move to output from the current blk of segment i
	for (int i = 0; i < segNum; i++) {
		segCur[i] = 0;
		segBlkCur[i] = 0;
	}
	for (int i = 0; i < segNum; i++) {
		if ((blk[i] = readBlockFromDisk(segAddr + i*segSize, buf)) == NULL) {
			perror("Reading Block Failed!\n");
			return -1;
		}
	}
	while (true) {
		bool allEmpty = true;
		for (int i = 0; i < segNum; i++) {
			// if all tuples of segment i have been moved to output
			if (segBlkCur[i] == TUPLE_PER_BLK) {
				segCur[i]++;
				segBlkCur[i] = 0;
				freeBlockInBuffer(blk[i], buf);
				if (segCur[i] != segBlkNum[i]) {
					// read a new blk from segment i
					if ((blk[i] = readBlockFromDisk(segAddr + i*segSize + segCur[i], buf)) == NULL) {
						perror("Reading Block Failed!\n");
						return -1;
					}
				}
			}
			if (segCur[i] != segBlkNum[i]) {
				allEmpty = false;
			}
		}
		if (allEmpty) { break; }
		// find the smallest tuple
		int minSeg = -1;
		Relation minTuple;
		for (int i = 0; i < segNum; i++) {
			if (segCur[i] == segBlkNum[i]) {
				continue;
			}
			Relation curTuple;
			memcpy(&curTuple, blk[i] + segBlkCur[i]*8, 8);
			if (minSeg == -1 || curTuple.attr1 < minTuple.attr1) {
				minSeg = i;
				minTuple = curTuple;
			}
		}
		// move the smallest tuple to output
//		cout << minTuple.attr1 << "\t" << minTuple.attr2 << endl;
		segBlkCur[minSeg]++;
		pushToWrite(buf, (unsigned char *)&minTuple, 8, retAddr);
	}
	// write the remaining tuples to disk
	pushToWrite(buf, NULL, 0, retAddr, false, true);
	cout << "numIO after mergesort.merge: " << buf->numIO << endl;
}
