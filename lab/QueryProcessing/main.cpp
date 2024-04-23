#include <iostream>
#include "extmem.h"
#include "file.h"
#include "blkio.h"
#include "select.h"
#include "project.h"
#include "join.h"

using namespace std;

int main()
{
//	cout << buf.numIO << " " << buf.numAllBlk << " " << buf.numFreeBlk << endl;

	// delete the old result files upon start every time
	char filename[40];
	for (int i = SELECT_RET_ADDR; i < HASH_S_ADDR + OFFSET; i++) {
		sprintf(filename, "%d.blk", i);
		remove(filename);
	}
	Buffer testBuf;
	if (!initBuffer(BUF_SIZE, BLK_SIZE, &testBuf)) {
		perror("Buffer Initialization Failed!\n");
		return -1;
	}
	pushToWrite(&testBuf, NULL, 0, 500000, true);
	freeBuffer(&testBuf);

	string cmd;
	cout << "Welcome!" << endl << endl;
	while (true) {
		// recreate the buffer every time
		Buffer buf; // A buffer
		if (!initBuffer(BUF_SIZE, BLK_SIZE, &buf)) {
			perror("Buffer Initialization Failed!\n");
			return -1;
		}
		cout << "> ";
		getline(cin, cmd);
		if (cmd == "exit") { // exit the program
			cout << "Bye!" << endl << endl;
			break;
		} else if (cmd == "select") { // select * from R where R.A = 40 or S.C = 60
			select(&buf);
		} else if (cmd == "project") { // select A from R
			project(&buf);
		} else if (cmd == "nlj") { // nested-loop-join
			nestedLoopJoin(&buf);
		} else if (cmd == "hj") { // hash-join
			hashJoin(&buf);
		} else if (cmd == "smj") { // sort-merge-join
			sortMergeJoin(&buf);
		}
		freeBuffer(&buf);
	}

	return 0;
}
