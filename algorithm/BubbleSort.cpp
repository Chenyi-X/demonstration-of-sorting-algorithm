#include <all.h>

void BubbleSort(RcdSqList &L) {
    system("cls");

    cout << endl << "冒泡排序" << endl << endl;
    cout << "排序前：" << endl << endl;
    cout << "length is " << L.length << endl;
    ofstream out("out.txt", ios::app);
    out << endl << "冒泡排序" << endl << endl;
    out << "排序前：" << endl << endl;
    out << "length is " << L.length << endl;
    print(L);
    fprint(L);
    system("pause");
    // 冒泡排序
    count1 = 0;
    for (int i = 1; i < L.length - 1; i++) {
        for (int j = 1; j <= L.length - i; j++) {
            if (L.rcd[j].key > L.rcd[j + 1].key) {
                swap(L.rcd[j], L.rcd[j + 1]);

                cout << endl << "The number of times being exchanged now:" << ++count1 << endl;
                out << endl << "The number of times being exchanged now:" << count1 << endl;
                print(L);
                fprint(L);

                system("pause");
            }
        }
    }
    cout << "------------------------------";
    cout << endl << "Total number of bubbles coming out:" << count1 << endl;
    cout << "------------------------------" << endl;

    out << "------------------------------";
    out << endl << "Total number of bubbles coming out:" << count1 << endl;
    out << "------------------------------" << endl;
    out.close();
    system("pause");
}


void BubbleSortTime(RcdSqList& L) {
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
    // 冒泡排序
    count1 = 0;
    for (int i = 1; i < L.length - 1; i++) {
        for (int j = 1; j <= L.length - i; j++) {
            if (L.rcd[j].key > L.rcd[j + 1].key) {
                swap(L.rcd[j], L.rcd[j + 1]);
            }
        }
        cout << endl << "Number of bubbles coming out:" << ++count1 << endl;
        out  << endl << "Number of bubbles coming out:" << ++count1 << endl;
        print(L);
        fprint(L);
    }
    cout << "------------------------------";
    cout << endl << "Total number of bubbles coming out:" << count1 << endl;
    cout << "------------------------------" << endl;

    out  << "------------------------------";
    out  << endl << "Total number of bubbles coming out:" << count1 << endl;
    out  << "------------------------------" << endl;
    out.close();
    
}
