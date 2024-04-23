//
// Created by zl on 2023/12/11.
//

#include <iostream>
#include "select.h"
#include "file.h"
#include "blkio.h"

using namespace std;

int select(Buffer *buf)
{
	/**
	 * select * from R where R.A = 40 or S.C = 60;
	 */
	const int targetA = 40;
	const int targetC = 60;

	// get a block for write
	pushToWrite(buf, NULL, 0, SELECT_RET_ADDR, true);

	// process R
	for (int i = 0; i < R_BLK_NUM; i++) {
		// read a blk from R and parse it into A and B
		unsigned char *blk;
		if ((blk = readBlockFromDisk(R_ADDR + i, buf)) == NULL) {
			perror("Reading Block Failed!\n");
			return -1;
		}
		Relation R[TUPLE_PER_BLK];
		readTuplesFromBlock(blk, R);
		// select tuples from R
		for (int j = 0; j < TUPLE_PER_BLK; j++) {
			if (R[j].attr1 == targetA) {
				cout << R[j].attr1 << "\t" << R[j].attr2 << endl;
				pushToWrite(buf, (unsigned char *)&R[j], 8, SELECT_RET_ADDR);
			}
		}
		freeBlockInBuffer(blk, buf);
	}

	// process S
	for (int i = 0; i < S_BLK_NUM; i++) {
		// read a blk from S and parse it into C and D
		unsigned char *blk;
		if ((blk = readBlockFromDisk(S_ADDR + i, buf)) == NULL) {
			perror("Reading Block Failed!\n");
			return -1;
		}
		Relation S[TUPLE_PER_BLK];
		readTuplesFromBlock(blk, S);
		// select tuples from S
		for (int j = 0; j < TUPLE_PER_BLK; j++) {
			if (S[j].attr1 == targetC) {
				cout << S[j].attr1 << "\t" << S[j].attr2 << endl;
				pushToWrite(buf, (unsigned char *)&S[j], 8, SELECT_RET_ADDR);
			}
		}
		freeBlockInBuffer(blk, buf);
	}

	// write the remaining tuples to disk
	pushToWrite(buf, NULL, 0, SELECT_RET_ADDR, false, true);

	cout << "numIO: " << buf->numIO << endl;
	return 0;
}
