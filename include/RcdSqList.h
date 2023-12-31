#pragma once

typedef  int  KeyType;  // 关键字类型为整数类型

#define DEFAULT_LENGTH 10

typedef  struct {
    KeyType  key;       // 关键字项
} RecordType, RcdType;  // 记录类型，RcdType为RecordType的简写

struct RcdSqList {
    RcdType* rcd;  // 存储空间基址，0号单元未用
    int length;    // 当前长度
    int size;      // 存储容量 
};  // 记录的顺序表

void Listcpy(RcdSqList& L1, RcdSqList& L2);
int Partition(RcdType rcd[], int low, int high);
void QSort_rec(RcdType rcd[], int s, int t);

