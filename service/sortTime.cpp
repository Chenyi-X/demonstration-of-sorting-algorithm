#include <all.h>

void sortTime(RcdSqList L) {

    RcdSqList L1, L2;
    Listcpy(L1, L); Listcpy(L2, L);

    clock_t start1, finish1;
    start1 = clock();
    BubbleSortTime(L1);
    finish1 = clock();
    double duration1 = static_cast<double>(finish1 - start1) / CLOCKS_PER_SEC;
    cout << "BubbleSort time:" << duration1 << endl;
    cout << endl;
    system("pause");

    clock_t start2, finish2;
    start2 = clock();
    InsertSortTime(L2);
    finish2 = clock();
    double duration2 = static_cast<double>(finish2 - start2) / CLOCKS_PER_SEC;
    cout << "InsertSort time:" << duration2 << endl;
    cout << endl;
    system("pause");

    clock_t start3, finish3;
    start3 = clock();
    QuickSortTime(L);
    finish3 = clock();
    double duration3 = static_cast<double>(finish3 - start3) / CLOCKS_PER_SEC;
    cout << " QuickSort time:" << duration1 << endl;
    system("pause");

    system("cls");

    cout << "BubbleSort time:" << duration1 << endl;
    cout << endl;
    cout << "InsertSort time:" << duration2 << endl;
    cout << endl;
    cout << " QuickSort time:" << duration1 << endl;

    ofstream out("out.txt",ios::app);

    out  << "BubbleSort time:" << duration1 << endl;
    out  << endl;
    out  << "InsertSort time:" << duration2 << endl;
    out  << endl;
    out  << " QuickSort time:" << duration1 << endl;

    out.close();

    system("pause");
}