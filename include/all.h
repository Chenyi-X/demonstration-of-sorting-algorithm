#pragma once

#ifndef ALL.H 


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

#include "RcdSqList.h"

using namespace std;

void init();
void displayMenu();
void showPower();
int  listCreate();
void showAlgorithm();
void showFile();

RcdSqList createFromFile(const string &fileName);
RcdSqList createRandom(int length);

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

#endif ALL.H 

