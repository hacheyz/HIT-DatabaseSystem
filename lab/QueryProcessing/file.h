//
// Created by zl on 2023/12/11.
//

#ifndef QUERYPROCESSING_FILE_H
#define QUERYPROCESSING_FILE_H

#define BUF_SIZE 520
#define BLK_SIZE 64
#define PTR_SIZE 4

#define SORT_R false
#define SORT_S true

#define R_NUM 112
#define S_NUM 224
#define TUPLE_PER_BLK 7
#define R_BLK_NUM (R_NUM / TUPLE_PER_BLK)
#define S_BLK_NUM (S_NUM / TUPLE_PER_BLK)
#define BUCKET_NUM 6
#define HASH_PER_BLK 6

#define R_ADDR 0
#define S_ADDR (R_ADDR + R_BLK_NUM)
#define OFFSET 1000
#define SELECT_RET_ADDR OFFSET
#define PROJECT_RET_ADDR (2*OFFSET)
#define NLJ_RET_ADDR (3*OFFSET)
#define HJ_RET_ADDR (4*OFFSET)
#define SMJ_RET_ADDR (5*OFFSET)
#define MERGE_R_SEG_ADDR (10*OFFSET)
#define MERGE_R_RET_ADDR (11*OFFSET)
#define MERGE_S_SEG_ADDR (12*OFFSET)
#define MERGE_S_RET_ADDR (13*OFFSET)
#define HASH_R_ADDR (20*OFFSET)
#define HASH_S_ADDR (21*OFFSET)

struct Relation {
	int attr1;
	int attr2;
};

struct Relation3 {
	int attr1;
	int attr2;
	int attr3;
};

struct Hash {
	int key;
	int attr1;
	int attr2;
};

#endif //QUERYPROCESSING_FILE_H
