//
// Created by zl on 2023/12/11.
//

#ifndef QUERYPROCESSING_JOIN_H
#define QUERYPROCESSING_JOIN_H

#include "extmem.h"

int sortMergeJoin(Buffer *buf);
int nestedLoopJoin(Buffer *buf);
int hashJoin(Buffer *buf);

#endif //QUERYPROCESSING_JOIN_H
