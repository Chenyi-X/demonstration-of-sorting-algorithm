#include "all.h"
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

