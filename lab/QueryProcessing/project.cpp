//
// Created by zl on 2023/12/11.
//

#include <iostream>
#include "project.h"
#include "file.h"
#include "blkio.h"
#include "mergeSort.h"

using namespace std;

int project(Buffer *buf)
{
	/**
	 * select A from R;
	 */
	mergeSort(buf, SORT_R);

	// do projection
	// get a block for write
	pushToWrite(buf, NULL, 0, PROJECT_RET_ADDR, true);
	int lastA = -1; // the last attribute A been outputed
	for (int i = 0; i < R_BLK_NUM; i++) {
		// read a blk from R and parse it into A and B
		unsigned char *blk;
		if ((blk = readBlockFromDisk(MERGE_R_RET_ADDR + i, buf)) == NULL) {
			perror("Reading Block Failed!\n");
			return -1;
		}
		Relation R[TUPLE_PER_BLK];
		readTuplesFromBlock(blk, R);
		for (int j = 0; j < TUPLE_PER_BLK; j++) {
			if (R[j].attr1 != lastA) {
				cout << R[j].attr1 << endl;
				pushToWrite(buf, (unsigned char *)&R[j].attr1, 4, PROJECT_RET_ADDR);
				lastA = R[j].attr1;
			}
		}
		freeBlockInBuffer(blk, buf);
	}
	pushToWrite(buf, NULL, 0, PROJECT_RET_ADDR, false, true);
	cout << "total numIO: " << buf->numIO << endl;

	return 0;
}