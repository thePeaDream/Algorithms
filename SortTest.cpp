#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#define NUM 10000
#define TESTNUM 10
using namespace std;
void BubbleSort(vector<int>&);
void BubbleSortReverse(vector<int>&);
void InsertSort(vector<int>&);
void InsertSortReverse(vector<int>&);
void HeapSort(vector<int>&);

void NumberGenerator(vector<int>& v)
{
  for(int i = 0; i < NUM; i++)
  {
    v.push_back(rand()%100);
  }
}


void TestBubbleS()
{

  vector<int> v;
  for(int i = 0; i < TESTNUM; i++)
  {
    v.push_back(rand()%100);
  }
  BubbleSort(v);
  for(int i = 0; i < v.size(); i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;  
}

void TestInsertS()
{
  vector<int> v;
  for(int i = 0; i < TESTNUM; i++)
  {
    v.push_back(rand()%100);
  }
  InsertSort(v);
  for(int i = 0; i < v.size(); i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;

}

void TestHeapS()
{
  vector<int> v;
  for(int i = 0; i < TESTNUM; i++)
  {
    v.push_back(rand()%100);
  }
  HeapSort(v);
  for(int i = 0; i < v.size(); i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;
}



int main()
{
  srand((unsigned int)time(NULL));
  
  
  TestBubbleS();
  TestInsertS();
  TestHeapS();


  //冒泡排序测试
  vector<int> testBubbleSort;
  NumberGenerator(testBubbleSort);

  //冒泡排序随机情况
  clock_t begin = clock();
  BubbleSort(testBubbleSort);
  clock_t end = clock();
  cout << "冒泡排序随机情况的时间为" << difftime(end, begin) << "ms" << endl;

  //冒泡排序最坏情况
  begin = clock();
  BubbleSortReverse(testBubbleSort);//逆序
  end = clock();
  cout << "冒泡排序最坏情况的时间为" << difftime(end, begin) << "ms" << endl;
  cout << endl;


  //插入排序测试
  vector<int> testInsertSort;
  NumberGenerator(testInsertSort);

  //插入排序随机情况
  begin = clock();
  BubbleSort(testBubbleSort);
  end = clock();
  cout << "插入排序随机情况的时间为" << difftime(end, begin) << "ms" << endl;

  //插入排序最坏情况
  begin = clock();
  InsertSortReverse(testBubbleSort);//逆序
  end = clock();
  cout << "插入排序最坏情况的时间为" << difftime(end, begin) << "ms" << endl;
  cout << endl;


  //堆排序测试
  vector<int> testHeapSort;
  NumberGenerator(testHeapSort);
  
  //堆排序随机情况
  begin = clock();
  HeapSort(testHeapSort);
  end = clock();
  cout << "堆排序的随机情况的时间为" << difftime(end,begin)<<"ms" << endl;

  //堆排序最坏情况 因为排升序建大堆，但在已经升序时最大值都在后面，导致建堆时的向上调整的交换次数更高
  begin = clock();
  HeapSort(testHeapSort);
  end = clock();
  cout << "堆排序的最坏情况为" << difftime(end,begin) << "ms"<< endl;
  cout << endl;
  
  return 0;
}
