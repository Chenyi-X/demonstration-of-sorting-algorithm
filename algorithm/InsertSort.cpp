#include <all.h>

void InsertSort(RcdSqList &L) {
    system("cls");

    cout << endl << "插入排序" << endl << endl;
    cout << "排序前：" << endl << endl;
    cout << "length is " << L.length << endl;
    print(L);

    ofstream out("out.txt", ios::app);
    out << endl << "插入排序" << endl << endl;
    out << "排序前：" << endl << endl;
    out << "length is " << L.length << endl;
    fprint(L);

    system("pause");

    // 插入排序
    count2 = 0;
    int i, j;
    for (i = 1; i < L.length ; i++) {
        if (L.rcd[i + 1].key < L.rcd[i].key) {
            L.rcd[0] = L.rcd[i + 1];
            j = i + 1;
            do {
                j--;
                L.rcd[j + 1] = L.rcd[j];
            } while (L.rcd[0].key < L.rcd[j - 1].key);
            L.rcd[j] = L.rcd[0];
        }

        cout << endl << "The number of times being Inserted now:" << ++count2 << endl;
        print(L);

        out << endl << "The number of times being Inserted now:" << count2 << endl;
        fprint(L);

        system("pause");
    }
    cout << "------------------------------";
    cout <<endl<< "Total number of Inserting:" << count2 << endl ;
    cout << "------------------------------" << endl;


    out << "------------------------------";
    out << endl << "Total number of Inserting:" << count2 << endl;
    out << "------------------------------" << endl;
    out.close();

    system("pause");
}

void InsertSortTime(RcdSqList& L) {
    system("cls");

    cout << endl << "InsertSort" << endl << endl;
    cout << "Original Sequence" << endl << endl;
    cout << "length is " << L.length << endl;
    print(L);
    system("pause");
    ofstream out("out.txt", ios::app);
    out << endl << "插入排序" << endl << endl;
    out << "排序前：" << endl << endl;
    out << "length is " << L.length << endl;
    fprint(L);

    // 插入排序
    count2 = 0;
    int i, j;
    for (i = 1; i < L.length; i++) {
        if (L.rcd[i + 1].key < L.rcd[i].key) {
            L.rcd[0] = L.rcd[i + 1];
            j = i + 1;
            do {
                j--;
                L.rcd[j + 1] = L.rcd[j];
            } while (L.rcd[0].key < L.rcd[j - 1].key);
            L.rcd[j] = L.rcd[0];
        }

        cout << endl << "The number of times being Inserted now:" << ++count2 << endl;
        print(L);

        out << endl << "The number of times being Inserted now:" << ++count2 << endl;
        fprint(L);

    }

    cout << "------------------------------";
    cout << endl << "Total number of being Inserted:" << count2 << endl;
    cout << "------------------------------" << endl;

    out  << "------------------------------";
    out  << endl << "Total number of being Inserted:" << count2 << endl;
    out  << "------------------------------" << endl;
    out.close();
}
