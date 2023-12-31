#include "all.h"

void sort(RcdSqList& L) {
    //调用排序算法
    RcdSqList L1, L2;

    Listcpy(L1, L); Listcpy(L2, L);

    BubbleSort (L1);

    InsertSort (L2);

    QuickSort(L);

    return;
}