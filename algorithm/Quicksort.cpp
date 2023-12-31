#include "all.h"
#include "Stack.h"
//递归实现

int Partition(RcdType rcd[], int low, int high)
{ //一趟划分
    rcd[0] = rcd[low];         // 将枢轴移至数组的闲置分量　　
    while (low < high) {
        while (low < high && rcd[high].key >= rcd[0].key)
        {
            --high;
        }
        // 将比枢轴小的记录移到前端
        if (low == high) break;
        rcd[low] = rcd[high];
        ++low;

        

        while (low < high && rcd[low].key <= rcd[0].key)
        {
            ++low;
        }            
        // 将比枢轴大的记录移到后端
        if (low == high) break;
        rcd[high] = rcd[low];
        --high;
    }
    rcd[low] = rcd[0];

    cout << endl << endl << "This division is " << ++count3 << endl;
    cout << "pilovt is " << rcd[0].key << endl;
    print(RList);
    ofstream out("out.txt", ios::app);
    out << endl << endl << "This division is " << count3 << endl;
    out << "pilovt is " << rcd[0].key << endl;
    fprint(RList);

    system("pause");

    return low;
}

void QSort_rec(RcdType rcd[], int s, int t)
{
    if (s < t) {
        
        int pivot = Partition(rcd, s, t);
        QSort_rec(rcd, s, pivot - 1);
        QSort_rec(rcd, pivot + 1, t);
    }
}

//递归实现

void QuickSort(RcdSqList &L)
{
    
    system("cls");

    cout <<endl << "QuickSort" << endl << endl;
    cout << "排序前：" << endl << endl;
    cout << "length is " << L.length << endl;
    print(L);
    ofstream out("out.txt", ios::app);
    out << endl << "QuickSort" << endl << endl;
    out << "排序前：" << endl << endl;
    out << "length is " << L.length << endl;
    fprint(L);

    system("pause");

    count3 = 0;

    QSort_rec(L.rcd, 1, L.length);

    cout << "------------------------------";
    cout << endl << "Pivot positioning times:" << count3 << endl;
    cout << "------------------------------" << endl;
    out << "------------------------------";
    out << endl << "Pivot positioning times:" << count3 << endl;
    out << "------------------------------" << endl;
    out.close();
    system("pause");
}


int PartitionTime(RcdType rcd[], int low, int high)
{ //一趟划分
    rcd[0] = rcd[low];         // 将枢轴移至数组的闲置分量　　
    while (low < high) {
        while (low < high && rcd[high].key >= rcd[0].key)
        {
            --high;
        }
        // 将比枢轴小的记录移到前端
        if (low == high) break;
        rcd[low] = rcd[high];
        ++low;

        while (low < high && rcd[low].key <= rcd[0].key)
        {
            ++low;
        }
        // 将比枢轴大的记录移到后端
        if (low == high) break;
        rcd[high] = rcd[low];
        --high;
    }
    rcd[low] = rcd[0];

    cout << endl << endl << "This division is " << ++count3 << endl;
    cout << "pilovt is " << rcd[0].key << endl;
    print(RList);
    ofstream out("out.txt", ios::app);
    out << endl << "This division is " << count3 << endl;
    out << "pilovt is " << rcd[0].key << endl;
    fprint(RList);

    return low;
}



//迭代实现

void QuickSortTime(RcdSqList& L) {

    system("cls");

    cout << endl << "BubbleSort" << endl << endl;
    cout << "Original sequence" << endl << endl;
    cout << "length is " << L.length << endl;
    ofstream out("out.txt", ios::app);
    out << endl << "冒泡排序" << endl << endl;
    out << "排序前：" << endl << endl;
    out << "length is " << L.length << endl;
    print(L);
    fprint(L);
    system("pause");


    count3 = 0;

    int low = 1;
    int high = L.length;
    SqStack stack;
    InitStack_Sq(stack, L.length + 1, INCREMENT);

    // Push initial values of low and high to the stack
    Push_Sq(stack, low);
    Push_Sq(stack, high);

    while (StackEmpty_Sq(stack) == FALSE) {
        // Pop high and low
        Pop_Sq(stack, high);
        Pop_Sq(stack, low);

        // Partition the array, get pivot index
        int pivotIndex = PartitionTime(L.rcd, low, high);

        // If there are elements on the left side of the pivot, push them to the stack
        if (pivotIndex - 1 > low) {
            Push_Sq(stack, low);
            Push_Sq(stack, pivotIndex - 1);
        }

        // If there are elements on the right side of the pivot, push them to the stack
        if (pivotIndex + 1 < high) {
            Push_Sq(stack, pivotIndex + 1);
            Push_Sq(stack, high);
        }
    }

    cout << "------------------------------";
    cout << endl << "Pivot positioning times:" << count3 << endl;
    cout << "------------------------------" << endl;
    out << "------------------------------";
    out << endl << "Pivot positioning times:" << count3 << endl;
    out << "------------------------------" << endl;
    out.close();

}