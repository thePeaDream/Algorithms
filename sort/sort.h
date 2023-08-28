#pragma once
#include <iostream>
#include <vector>
#include <time.h>
#include <stack>
#include<assert.h>
#include <time.h>
#include <stdlib.h>
using namespace std;
void printVector(vector<int>& v);

void insertSort(vector<int>& v);
void insertSort(vector<int>& v, int begin, int end);

void shellSort(vector<int>& v);
void seleteSort(vector<int>& v);
void bubbleSort(vector<int>& v);

void adjustDown(vector<int>& v, int adjust, int end);//向下调整算法
void heapSort(vector<int>& v);

int getMidKeyi(const vector<int>& v, int begin, int end);//三数取中
int quickPartSortHoare(vector<int>& v, int begin, int end);
int quickPartSortHole(vector<int>& v, int begin, int end);
int quickPartSortPreCur(vector<int>& v, int begin, int end);
void quickSortChild(vector<int>& v, int begin, int end);
void quickSortR(vector<int>& v);
void quickSortNotR(vector<int>& v);

void mergeSort(vector<int>& v);
void mergeSortChild(vector<int>& v, int begin, int end, int* tmp);
void singleMerge(vector<int>& v, int begin1, int end1, int begin2, int end2, int pos, int* tmp);//二路归并
void mergeSortNotR(vector<int>& v);