//
// Created by zl on 2023/12/11.
//

#ifndef QUERYPROCESSING_BLKIO_H
#define QUERYPROCESSING_BLKIO_H

#include "extmem.h"
#include "file.h"

void pushToWrite(Buffer *buf, unsigned char *source, size_t size, unsigned int addr, bool reset = false, bool push = false);
void readTuplesFromBlock(unsigned char *blk, Relation *R);
void output(Buffer *buf, unsigned int addr, int attr1, int attr2, int attr3);
void pushHashToWrite(Buffer *buf, Relation *R, unsigned int addr, bool reset = false, bool push = false);
int readHashFromBlock(unsigned char *blk, Relation *R);

#endif //QUERYPROCESSING_BLKIO_H
