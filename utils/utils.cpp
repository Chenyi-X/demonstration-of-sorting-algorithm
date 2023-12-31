#include <all.h>

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