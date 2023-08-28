#include "sort.h"
using namespace std;

//����ȡ��
void testGetMidKeyi()
{
	srand((unsigned)time(nullptr));

	//��������
	vector<int> v;
	//������
	int num = 10000;
	for (int i = 0; i < num; ++i)
		v.push_back(rand() % num);

	//�Ȱ������ź���
	heapSort(v);

	//��������ȡ�к󣬿�����������������������
	//clock()���س������е�����λ�����õĺ�����
	clock_t begin = clock();
	quickSortR(v);
	clock_t end = clock();
	cout << "�����ٶȣ�" << end - begin << endl;
}

//С�����Ż�
void testRangeOptimize()
{
	srand((unsigned)time(nullptr));

	//��������
	vector<int> v;
	//������
	int num = 1000000;
	for (int i = 0; i < num; ++i)
		v.push_back(rand() % num);

	clock_t begin = clock();
	quickSortR(v);
	clock_t end = clock();
	cout << "�����ٶȣ�" << end - begin << endl;
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