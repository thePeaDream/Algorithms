#include "sort.h"
using namespace std;
//1 直接插入排序O(N^2)
//将待排序的元素，逐一插入到 有序序列 中
//初始的有序序列：只有1个元素
void insertSort(vector<int>& v)
{
	for (int i = 0; i < v.size() - 1; ++i) // 表示要插入的元素数目
	{
		//单次插入

		//[0,end]有序，将end+1位置的值插入到前面
		int end = i;
		int insertEle = v[end + 1];

		//用end反向遍历有序序列(升序为例)，挪动数据并找到插入位置
		//比insertEle大的数都往后挪动
		while (end >= 0)
		{
			if (insertEle < v[end])
			{
				v[end + 1] = v[end];
				--end;
			}
			else
				break;
		}
		//此时插入位置为end+1
		v[end + 1] = insertEle;
	}
}

void insertSort(vector<int>& v, int left, int right)
{
	for (int i = left; i < right; ++i)
	{
		//单次插入
		//[left, end]有序,将end + 1 的位置的值插入到前面
		int end = i;
		int insertEle = v[end + 1];
		while (end >= left)
		{
			if (insertEle < v[end])
			{
				v[end + 1] = v[end];
				--end;
			}
			else
				break;
		}
		v[end + 1] = insertEle;
	}
}

//2 希尔排序
//A 预排序：
//第一步：先分组，间隔为group的元素为一组，一共group组
//第二步：对这group组数据，分别进行直接插入排序
//B 对所有数据进行直接插入排序
/*void  shellSort1(vector<int>& v)
{
	int group;
	for (int j = 0; j < group; j++)
	{
		for (size_t i = j; i < v.size() - group; i += group)//j = 0第一组; j = 1第二组
		{
			//当前组位于[0, end]位置的值有序，将end+group位置的值插入到前面，保证仍然有序
			int end = i;
			int insertEle = v[end + group];

			//用end反向遍历有序序列(当前组的),挪动数据并找到插入位置
			while (end >= 0)
			{
				if (insertEle < v[end])
				{
					//往后挪group步,因为数据相差group步
					v[end + group] = v[end];
					end -= group;
				}
				else
					break;
			}
			//插入元素
			v[end + group] = insertEle;
		}
	}
}*/
void printVector(vector<int>& v)
{
	for (auto x : v)
	{
		cout << x << " ";
	}
	cout << endl;
}

//gap>1时,预排序
//gap = 1,直接插入排序
void  shellSort(vector<int>& v)
{
	int gap = v.size() / 2;
	//gap > 1时，都是预排序；
	//gap = 1，直接插入排序，此时数据已经 接近有序/有序
	while (gap >= 1)
	{
		for (int i = 0; i < v.size() - gap; ++i) //gap组数据交替进行直接插入排序
		{
			//当前组的[0,end]内的元素有序，将end + gap位置的值插入
			int end = i;
			int insertEle = v[end + gap];

			//单次插入
			//用end反向遍历当前组的有序序列
			//比insertEle大的数据往后挪gap步,同时找到插入位置
			while (end >= 0)
			{
				if (insertEle < v[end])
				{
					v[end + gap] = v[end];
					end -= gap;
				}
				else
					break;
			}
			v[end + gap] = insertEle;
		}
		//更新gap前，看当前gap的处理结果
		//cout << "gap：" << gap << "-> ";
		//printVector(v);

		gap /= 2;
	}
}

void seleteSort(vector<int>& v)
{
	//在[begin,v.size() - 1]区间选出最小的数，放到begin,接着++begin
	//直到这个区间只剩下一个元素，即begin == v.size() - 1时停止
	for (int begin = 0; begin < v.size() - 1; ++begin)
	{
		//先假设v[begin]最小

		//最小值下标(用于最后交换数据)
		int minIndex = begin;
		//对应的最小值(用于比较)
		int min = v[minIndex];

		//遍历begin之后的数
		//若比min小，记录它的下标和值
		for (int j = begin + 1; j < v.size(); ++j)
		{
			if (v[j] < min)
			{
				minIndex = j;
				min = v[j];
			}
		}

		//此时minIndex为最小值下标,把 最小值位置 和 begin位置 的值做交换
		swap(v[minIndex], v[begin]);
	}
}

//adjust:要向下调整的位置，adjust位置结点的左孩子和右孩子必须都是大堆
//end：堆的元素下标最大值[左闭右开)
void adjustDown(vector<int>& v, int adjust, int end)
{
	//待调整的结点有孩子，才可以向下调整
	while (adjust * 2 + 1 < end)
	{
		//假设最大的孩子是左孩子
		int maxChild = adjust * 2 + 1;

		//如果右孩子存在且大于左孩子
		if (maxChild + 1 < end && v[maxChild + 1] > v[maxChild])
		{
			++maxChild;
		}

		//如果待调整结点小于最大的孩子，需要向下调整，否则直接结束
		if (v[maxChild] > v[adjust])
		{
			swap(v[maxChild], v[adjust]);
			adjust = maxChild;
		}
		else
			break;
	}
}

void heapSort(vector<int>& v)
{
	//1 建堆(向下调整建堆) ——  从最后一个非叶子结点开始建堆
	//即最后一个结点的父结点
	for (int i = ((v.size() - 1) - 1) / 2; i >= 0; --i)
	{
		adjustDown(v, i, v.size());
	}

	//  2 交换堆顶元素选数 + 调堆
	for (int i = v.size() - 1; i > 0; --i)
	{
		//把选出的最大值交换到末尾
		swap(v[i], v[0]);

		//将剩下的数调整成堆,
		adjustDown(v, 0, i); //这里是左闭右开，不会包含i
	}
}

void bubbleSort(vector<int>& v)
{
	//每一次冒泡都能让待排序序列的最大值放到末尾，待排序的元素数目-1
	//要进行v.size() - 1次冒泡
	for (int i = 0; i < v.size() - 1; ++i)//i表示完成的冒泡次数
	{
		//标识此次冒泡是否有发生交换
		bool flag = false;

		//其中一次冒泡
		//begin和begin+1位置的值比较，大的交换到右边
		for (int begin = 0; begin < v.size() - 1 - i; ++begin)//待排序序列的末尾会改变
		{
			if (v[begin] > v[begin + 1])
			{
				swap(v[begin], v[begin + 1]);
				flag = true;
			}
		}

		//若此次冒泡没有发生交换，说明已经有序
		if (flag == false)
			return;
	}
}

//三数取中,返回中间值的下标
int getMidKeyi(const vector<int>& v, int begin, int end)
{
	int mid = (begin + end) / 2;

	if (v[begin] < v[mid])
	{
		if (v[mid] < v[end])
			return mid;
		//否则mid位置为最大值
		else if (v[begin] < v[end])//次大值即为中间值
			return end;
		else
			return begin;
	}
	else//v[begin] > v[mid]
	{
		if (v[end] > v[begin])
			return begin;
		//否则begin位置为最大值
		else if (v[mid] < v[end])//找次大值
			return end;
		else
			return mid;
	}
}

//快速排序单趟：hoare版本
//[begin, end]是要进行单趟排序的区间
int quickPartSortHoare(vector<int>& v, int begin, int end)
{
	//三数取中
	//int tmp = getMidKeyi(v, begin, end);
	//swap(v[begin], v[tmp]);

	//key位置
	int keyi = begin;
	//选区间第一个数为key
	int key = v[begin];

	while (begin < end)
	{
		//左边做key，右边先走(为了保证相遇位置的值，比key小)

		//右边找小，v[end]大就一直往前找
		while (begin < end && v[end] >= key)
			--end;

		//左边找大，v[begin]小就一直往后找
		while (begin < end && v[begin] <= key)
			++begin;

		//情况1：begin = end;
		//情况2：v[begin] > key且v[end] < key，即左边找到大,右边找到小
		swap(v[begin], v[end]);
	}

	//交换 key位置 和 相遇位置 的值
	swap(v[keyi], v[begin]);

	//更新keyi，返回基准值新下标
	keyi = begin;
	return keyi;
}

//快速排序单趟：挖坑法
int quickPartSortHole(vector<int>& v, int begin, int end)
{
	//三数取中
	//int tmp = getMidKeyi(v, begin, end);
	//swap(v[begin], v[tmp]);

	int key = v[begin];

	//基准值的位置形成坑
	int hole = begin;
	while (begin < end)
	{
		//右边找小
		while (begin < end && v[end] >= key)
			--end;
		//找到以后，把值填进旧坑位，end位置形成新的坑位
		v[hole] = v[end];
		hole = end;

		//左边找大
		while (begin < end && v[begin] <= key)
			++begin;
		//找到以后，把值填进旧坑位，begin位置形成新的坑位
		v[hole] = v[begin];
		hole = begin;
	}

	//最后相遇在坑位
	v[hole] = key;
	return hole;
}

//快速排序单趟：前后指针版本
int quickPartSortPreCur(vector<int>& v, int begin, int end)
{
	//三数取中
	int tmp = getMidKeyi(v, begin, end);
	swap(v[begin], v[tmp]);

	//选择基准值
	int key = v[begin];

	//初始化前后指针
	int pre = begin;
	int cur = begin + 1;

	while (cur <= end)
	{
		if (v[cur] < key)
		{
			++pre;
			swap(v[pre], v[cur]);
		}
		++cur;
	}
	//此时pre前面的数(包括pre指向的数)都是小于基准值（除基准值外）
	swap(v[pre], v[begin]);
	//交换后基准值的位置就是pre
	return pre;
}
void quickSortChild(vector<int>& v, int begin, int end)
{
	if (begin >= end)
		return;
	//如果这个区间只有9个数
	if (end - begin + 1 <= 9)
	{
		//写一个在[begin, end]区间进行插入排序的函数
		insertSort(v, begin, end);
		return;
	}
	//单趟排序任选一种
	//int keyi = quickPartSortHoare(v, begin, end);
	//int keyi = quickPartSortHole(v, begin, end);

	//先处理 基准值，将基准值排到正确位置
	int keyi = quickPartSortPreCur(v, begin, end);

	//处理左区间和右区间
	//左区间：[begin, keyi - 1]
	//右区间：[keyi + 1, end]
	quickSortChild(v, begin, keyi - 1);
	quickSortChild(v, keyi + 1, end);
}
void quickSortR(vector<int>& v)
{
	quickSortChild(v, 0, v.size() - 1);
}



//非递归
void quickSortNotR(vector<int>& v)
{
	//存储区间
	stack<int> st;

	//[0, v.size() - 1]
	//栈后进先出，所以先入 区间右边
	st.push(v.size() - 1);
	st.push(0);

	while (!st.empty())
	{
		//当前区间出栈，准备处理
		int left = st.top();
		st.pop();
		int right = st.top();
		st.pop();

		//处理当前区间的基准值
		int keyi = quickPartSortPreCur(v, left, right);

		//将当前区间分为 左区间 和 右区间
		//[left,keyi - 1]  [keyi + 1, right]
		//区间存在且大于一个数，区间入栈
		if (right > keyi + 1)
		{
			st.push(right);
			st.push(keyi + 1);
		}
		if (keyi - 1 > left)
		{
			st.push(keyi);
			st.push(left);
		}
	}
}


//将两段有序区间[begin1, end1] [begin2, end2]合并成一段，放入tmp中
void singleMerge(vector<int>& v, int begin1, int end1, int begin2, int end2, int* tmp)
{
	int i = 0;

	//任一区间数据放完就结束
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (v[begin1] <= v[begin2])
			tmp[i++] = v[begin1++];
		else if (v[begin2] < v[begin1])
			tmp[i++] = v[begin2++];
	}

	//然后把另一个区间剩下数据拷贝回去
	while (begin1 <= end1)
		tmp[i++] = v[begin1++];
	while (begin2 <= end2)
		tmp[i++] = v[begin2++];
}

//将两段有序区间[begin1, end1] [begin2, end2]合并成一段，放入tmp中，起始位置是pos
void singleMerge(vector<int>& v, int begin1, int end1, int begin2, int end2, int pos, int* tmp)
{
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (v[begin1] <= v[begin2])
			tmp[pos++] = v[begin1++];
		else if (v[begin2] < v[begin1])
			tmp[pos++] = v[begin2++];
	}

	while (begin1 <= end1)
		tmp[pos++] = v[begin1++];
	while (begin2 <= end2)
		tmp[pos++] = v[begin2++];
}

void mergeSortChild(vector<int>& v, int begin, int end, int* tmp)
{
	if (begin >= end)
		return;
	int mid = (begin + end) / 2;

	int begin1 = begin;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = end;
	int pos = begin;

	//[begin1, end1]  [begin2, end2] 分治递归，让子区间有序
	mergeSortChild(v, begin1, end1, tmp);
	mergeSortChild(v, begin2, end2, tmp);

	//将两个有序区间归并到tmp中，起始位置为pos
	singleMerge(v, begin1, end1, begin2, end2, pos, tmp);

	//将归并好的tmp中数据 拷贝回原序列
	while (begin <= end)
	{
		v[begin] = tmp[begin];
		++begin;
	}
}

void mergeSort(vector<int>& v)
{
	int* tmp = new int[v.size()];
	//左闭右闭(要进行归并排序的区间)
	mergeSortChild(v, 0, v.size() - 1, tmp);
	delete[] tmp;
}

void mergeSortNotR(vector<int>& v)
{
	if (v.size() <= 1)
		return;

	int* tmp = new int[v.size()];

	//标识几个元素为1组进行归并
	int group = 1;

	while (group < v.size())
	{
		for (int i = 0; i < v.size(); i += group * 2/*跳过两组数据*/)
		{
			//第一组
			int begin1 = i;
			int end1 = i + group - 1;

			//第二组
			int begin2 = i + group;
			int end2 = i + 2 * group- 1;

			int pos = i;

			//边界修正

			//如果end1越界，修正end1，同时说明第二组不可能存在
			if (end1 >= v.size())
			{
				end1 = v.size() - 1;
				begin2 = v.size();
				end2 = v.size() - 1;
			}
			//begin2越界，第二组数据不存在
			else if (begin2 >= v.size())
			{
				begin2 = v.size();
				end2 = v.size() - 1;
			}
			//只有end2越界，修正第二组数据即可
			else if (end2 >= v.size())
			{
				end2 = v.size() - 1;
			}

			//两组序列进行二路归并
			singleMerge(v, begin1, end1, begin2, end2, pos, tmp);
		}
		//遍历完当前所有的组，所有相邻组 归并后的结果保存在tmp中，结果拷贝回原序列		
		for (int j = 0; j < v.size(); ++j)
			v[j] = tmp[j];

		//更新一组数据的个数
		group *= 2;
	}
	delete[] tmp;
}
/*
void countSort(vector<int>& v)
{
	if (v.size() <= 1)
		return;
	int max = v[0];

	//遍历一遍待排序的数，选出max
	for (auto x : v)
	{
		if (x > max)
			max = x;
	}

	//直接映射
	int* tmp = new int[max + 1];
	memset(tmp, 0, (max + 1) * sizeof(int));
	//tmp下标代表v中出现的数字
	//tmp下标位置的值代表下标数字出现的次数

	//遍历v，tmp记录各个数字出现次数
	for (int i = 0; i < v.size(); ++i)
		tmp[v[i]]++;


	int j = 0;
	//遍历tmp
	for (int i = 0; i < max + 1; ++i)
	{
		while(tmp[i] > 0)
		{
			v[j++] = i;
			--tmp[i];
		}
	}
}*/

void countSort(vector<int>& v)
{
	if (v.size() <= 1)
		return;
	int max = v[0];
	int min = v[0];

	//遍历一遍待排序的数，选出max和min
	for (auto x : v)
	{
		if (x > max)
			max = x;
		if (x < min)
			min = x;
	}

	//间接映射 [min, max]
	int* tmp = new int[max - min + 1];
	//下标0 映射 min
	//下标max - min 映射 max 
	memset(tmp, 0, (max - min + 1) * sizeof(int));

	//遍历v，tmp记录各个数字出现次数
	for (int i = 0; i < v.size(); ++i)
		tmp[v[i] - min]++;

	int j = 0;
	//遍历tmp
	for (int i = 0; i < max - min + 1; ++i)
	{
		while (tmp[i] > 0)
		{
			v[j] = i + min;
			--tmp[i];
			++j;
		}
	}
}
