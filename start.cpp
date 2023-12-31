#include "all.h"

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