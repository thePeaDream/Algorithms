#include "sort.h"
using namespace std;

//三数取中
void testGetMidKeyi()
{
	srand((unsigned)time(nullptr));

	//创建数据
	vector<int> v;
	//数据量
	int num = 10000;
	for (int i = 0; i < num; ++i)
		v.push_back(rand() % num);

	//先把数据排好序
	heapSort(v);

	//加入三数取中后，可以算出，若不加入程序会崩溃
	//clock()返回程序运行到调用位置所用的毫秒数
	clock_t begin = clock();
	quickSortR(v);
	clock_t end = clock();
	cout << "快排速度：" << end - begin << endl;
}

//小区间优化
void testRangeOptimize()
{
	srand((unsigned)time(nullptr));

	//创建数据
	vector<int> v;
	//数据量
	int num = 1000000;
	for (int i = 0; i < num; ++i)
		v.push_back(rand() % num);

	clock_t begin = clock();
	quickSortR(v);
	clock_t end = clock();
	cout << "快排速度：" << end - begin << endl;
}

void testSort()
{
	vector<int> v;
	v.resize(7);
	for (size_t i = 0; i < v.size(); ++i)
		cin >> v[i];
	//insertSort(v, 1, 5);
	//insertSort(v);
	//shellSort(v);
	//seleteSort(v);
	//heapSort(v);
	//bubbleSort(v);
	//quickSortR(v);
	//quickSortNotR(v);
	//mergeSort(v);
	mergeSortNotR(v);
	//countSort(v);
	for (auto x : v)
	{
		cout << x << " ";
	}
}
int main()
{
	testSort();
	//testGetMidKeyi();
	//testRangeOptimize();
	return 0;
}