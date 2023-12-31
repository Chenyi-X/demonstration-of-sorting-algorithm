
#include <iostream>
#include <stdio.h>
#include <time.h>       //时间
#include <thread>       //线程暂停
#include <chrono>
#include <windows.h>    //cmd命令库
#include <fstream>      //文件读写
#include <string.h>
#include <ios>
#include <string>
#include <sstream>

using namespace std;

void init();
void displayMenu();
void showPower();
int  listCreate();
void showAlgorithm();
void showFile();

void sort(RcdSqList &L);
void sortTime(RcdSqList L);

void InsertSort(RcdSqList &L);
void BubbleSort(RcdSqList &L);
void  QuickSort(RcdSqList &L);

void BubbleSortTime (RcdSqList& L);
void InsertSortTime (RcdSqList& L);
void  QuickSortTime (RcdSqList& L);

void print(RcdSqList &L);
void fprint(RcdSqList& L);

extern int count1;
extern int count2;
extern int count3;

extern RcdSqList RList;


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
    int high = L.length, low = 1;
    int* stack = new int[L.length + 1];
    int top = -1;


    stack[++top] = low;
    stack[++top] = high;


    while (top >= 0) {

        high = stack[top--];
        low = stack[top--];


        int pivotIndex = PartitionTime(L.rcd, low, high);


        if (pivotIndex - 1 > low) {
            stack[++top] = low;
            stack[++top] = pivotIndex - 1;
        }


        if (pivotIndex + 1 < high) {
            stack[++top] = pivotIndex + 1;
            stack[++top] = high;
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

void sort(RcdSqList& L) {
    //调用排序算法
    RcdSqList L1, L2;

    Listcpy(L1, L); Listcpy(L2, L);

    BubbleSort (L1);

    InsertSort (L2);

    QuickSort(L);

    return;
}

RcdSqList createFromFile(const string& fileName) {

    RcdSqList rcdSqList;

    rcdSqList.size = DEFAULT_LENGTH + 1;
    rcdSqList.rcd = new RcdType[rcdSqList.size];
    rcdSqList.length = 0;

    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "Error opening file." << endl;
        return rcdSqList;
    }

    while (!file.eof()) {
        file >> rcdSqList.rcd[++rcdSqList.length].key;

        if (rcdSqList.length + 1 == rcdSqList.size) {

            rcdSqList.size *= 2;
            RcdType* newRcd = new RcdType[rcdSqList.size];
            newRcd[0].key = 0;
            for (int i = 1; i <= rcdSqList.length; i++) {
                newRcd[i] = rcdSqList.rcd[i];
            }
            delete[] rcdSqList.rcd;
            rcdSqList.rcd = newRcd;
        }
    }

    file.close();
    return rcdSqList;
}

RcdSqList createRandom(int length) {

    RcdSqList rcdSqList;

    srand(static_cast<unsigned int>(time(nullptr)));

    rcdSqList.rcd = new RcdType[length + 1];
    rcdSqList.size = length + 1;
    rcdSqList.length = 0;
    rcdSqList.rcd[0].key = 0;

    for (int i = 1; i < rcdSqList.size; i++) {
        rcdSqList.rcd[i].key = rand() % 999 + 1;
        rcdSqList.length++;
    }
    return rcdSqList;

}

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

RcdSqList RList;

void showPower() {

    system("cls");
    cout << "_________________________________________________" << endl;
    cout << "|                                               |" << endl;
    cout << "|There is a Sequence List with                  |" << endl;
    cout << "|a length of LENGTH randomly generated          |" << endl;
    cout << "|by the system.                                 |" << endl;
    cout << "|                                               |" << endl;
    cout << "|Now we use the sorting time                    |" << endl;
    cout << "|to process the same sequence                   |" << endl;
    cout << "|on the computer to evaluate its performance.   |" << endl;
    cout << "|                                               |" << endl;
    cout << "|The time will be output in the last line.      |" << endl;
    cout << "|                                               |" << endl;
    cout << "|Please input LENGTH below .                    |" << endl;
    cout << "|                                               |" << endl;
    cout << "|_______________________________________________|" << endl << endl;

    cout << endl << "Please input(Recommend over 100):                  " << endl;
    int len;
    cin >> len;

    RList = createRandom(len);
    sortTime(RList);

}

int listCreate() {
    system("cls");
    cout << endl;
    cout << "|1.Read the column to be sorted from the file        |" << endl;
    cout << "|2.Random                                            |" << endl;
    cout << "|                                                    |" << endl;
    cout << "|0.Return to the previous level                      |" << endl;

    int a = 1;
    int choice;

    while (a) {
        cout <<endl << "请输入你的选择:";
        cin >> choice;

        switch (choice) {
        case 1:
            showFile();
            RList = createFromFile("data.txt");
            a = 0;
            break;
        case 2:
            RList = createRandom(DEFAULT_LENGTH);
            a = 0;
            break;
        case 0:
            choice = 0;
            a = 0;
            break;
        default:
            printf("无效的选择，请重新输入");
            cout << endl;
            break;
        }
    }  
    return choice;
}

void showFile() {
    system("cls");
    cout << "_________________________________________________" <<  endl;
    cout << "|                                               |" << endl;
    cout << "|please input data into \"data.txt\"              |" << endl;
    cout << "|data should be separated by spaces.            |" << endl;
    cout << "|                                               |" << endl;
    cout << "|_______________________________________________|" << endl <<endl;
    system("pause");
}


void showAlgorithm() {
    //排序算法

    if(!listCreate())
        return;

    system("cls");
    cout << "_________________________________________________" << endl;
    cout << "|                                               |" << endl;
    cout << "|1.BubbuleSort                                  |" << endl;
    cout << "|2.InsertSort                                   |" << endl;
    cout << "|3.QuickSort                                    |" << endl;
    cout << "|                                               |" << endl;
    cout << "|0.exit                                         |" << endl;
    cout << "|_______________________________________________|" << endl << endl;
    cout << "请输入你的选择:";
    int choice;
    cin >> choice;
    int a = 1;
    while(a)

        switch (choice) {
        case 1:
            BubbleSort(RList);
            break;
        case 2:
            InsertSort(RList);
            break;
        case 3:
            QuickSort(RList);
            break;
        case 0:
            if (!listCreate())
                return;
            a = 0;
            break;
        default:
            printf("无效的选择，请重新输入。\n");
            break;
        }

}

void displayMenu() {
    system("cls");
    cout<<"__________________________________________________"<<endl;
    cout<<"|   Demonstration system of sorting algorithm    |"<<endl;
    cout<<"|                                                |"<<endl;
    cout<<"|name:陈翼                                       |"<<endl;
    cout<<"|student number:3122006207                       |"<<endl;
    cout<<"|Class:4                                         |"<<endl;
    cout<<"|_______________________________________________ |"<<endl;
    cout<<"|                                                |"<<endl;
    cout<<"|1.Demonstration of sorting algorithm (auto)     |"<<endl;
    cout<<"|                                                |"<<endl;
    cout<<"|2.Demonstration of sorting algorithm (only one) |"<<endl;
    cout<<"|                                                |"<<endl;
    cout<<"|3.Performance statistics of sorting algorithm   |"<<endl;
    cout<<"|                               (length >= 100)  |"<<endl;
    cout<<"|                                                |"<<endl;
    cout<<"|0.exit                                          |"<<endl;
    cout<<"--------------------------------------------------"<<endl<<endl;
    cout<<"请输入你的选择:";
}


int count1;
int count2;
int count3;

void init() {

    SetConsoleOutputCP(65001);//设置CMD为UTF8

    HANDLE hOut;
    COORD bufferSize;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    bufferSize.X = 100;
    bufferSize.Y = 60;
    SetConsoleScreenBufferSize(hOut, bufferSize);//调整CMD缓冲区大小

    TCHAR title[256];
    HWND hWnd;
    GetConsoleTitle(title, 246);
    hWnd = FindWindow(0, title);

}


void Listcpy(RcdSqList& L1, RcdSqList& L2) {
    L1.rcd = new RcdType[L2.size];
    L1.size = L2.size;
    L1.length = L2.length;
    for (int i = 0; i <= L2.length; i++) {
        L1.rcd[i] = L2.rcd[i];
    }
}


void print(RcdSqList& L) {

    cout << endl;
    for (int i = 1; i <= L.length; i++) {
        cout << L.rcd[i].key << " ";
        if ((i) % 10 == 0) {
            cout << endl;
        }
    }
    cout << endl;
    return;
}


void fprint(RcdSqList& L) {
    ofstream out("out.txt", ios::app);
    out << endl;
    for (int i = 1; i <= L.length; i++) {
        out << L.rcd[i].key << " ";
        if ((i) % 10 == 0) {
            out << endl;
        }
    }
    out << endl;
    return;
}

int main() {

    init();//初始化CMD

    int choice;
    while (1) {

        displayMenu();//展示菜单

        cin>>choice; 
        
        switch (choice) {
            case 1:               
                if (listCreate())   //若选择返回上级，不执行排序
                    sort(RList);
                break;
            case 2:
                showAlgorithm();
                break;
            case 3:
                showPower();
                break;
            case 0:
                printf("exit...\n");
                system("pause");
                return 0; 
            default:
                printf("无效的选择，请重新输入");
                cout << endl;
                system("pause");
                break;
        }
    }

    return 0;
}