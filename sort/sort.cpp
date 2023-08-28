#include "sort.h"
using namespace std;
//1 ֱ�Ӳ�������O(N^2)
//���������Ԫ�أ���һ���뵽 �������� ��
//��ʼ���������У�ֻ��1��Ԫ��
void insertSort(vector<int>& v)
{
	for (int i = 0; i < v.size() - 1; ++i) // ��ʾҪ�����Ԫ����Ŀ
	{
		//���β���

		//[0,end]���򣬽�end+1λ�õ�ֵ���뵽ǰ��
		int end = i;
		int insertEle = v[end + 1];

		//��end���������������(����Ϊ��)��Ų�����ݲ��ҵ�����λ��
		//��insertEle�����������Ų��
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
		//��ʱ����λ��Ϊend+1
		v[end + 1] = insertEle;
	}
}

void insertSort(vector<int>& v, int left, int right)
{
	for (int i = left; i < right; ++i)
	{
		//���β���
		//[left, end]����,��end + 1 ��λ�õ�ֵ���뵽ǰ��
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

//2 ϣ������
//A Ԥ����
//��һ�����ȷ��飬���Ϊgroup��Ԫ��Ϊһ�飬һ��group��
//�ڶ���������group�����ݣ��ֱ����ֱ�Ӳ�������
//B ���������ݽ���ֱ�Ӳ�������
/*void  shellSort1(vector<int>& v)
{
	int group;
	for (int j = 0; j < group; j++)
	{
		for (size_t i = j; i < v.size() - group; i += group)//j = 0��һ��; j = 1�ڶ���
		{
			//��ǰ��λ��[0, end]λ�õ�ֵ���򣬽�end+groupλ�õ�ֵ���뵽ǰ�棬��֤��Ȼ����
			int end = i;
			int insertEle = v[end + group];

			//��end���������������(��ǰ���),Ų�����ݲ��ҵ�����λ��
			while (end >= 0)
			{
				if (insertEle < v[end])
				{
					//����Ųgroup��,��Ϊ�������group��
					v[end + group] = v[end];
					end -= group;
				}
				else
					break;
			}
			//����Ԫ��
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

//gap>1ʱ,Ԥ����
//gap = 1,ֱ�Ӳ�������
void  shellSort(vector<int>& v)
{
	int gap = v.size() / 2;
	//gap > 1ʱ������Ԥ����
	//gap = 1��ֱ�Ӳ������򣬴�ʱ�����Ѿ� �ӽ�����/����
	while (gap >= 1)
	{
		for (int i = 0; i < v.size() - gap; ++i) //gap�����ݽ������ֱ�Ӳ�������
		{
			//��ǰ���[0,end]�ڵ�Ԫ�����򣬽�end + gapλ�õ�ֵ����
			int end = i;
			int insertEle = v[end + gap];

			//���β���
			//��end���������ǰ�����������
			//��insertEle�����������Ųgap��,ͬʱ�ҵ�����λ��
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
		//����gapǰ������ǰgap�Ĵ�����
		//cout << "gap��" << gap << "-> ";
		//printVector(v);

		gap /= 2;
	}
}

void seleteSort(vector<int>& v)
{
	//��[begin,v.size() - 1]����ѡ����С�������ŵ�begin,����++begin
	//ֱ���������ֻʣ��һ��Ԫ�أ���begin == v.size() - 1ʱֹͣ
	for (int begin = 0; begin < v.size() - 1; ++begin)
	{
		//�ȼ���v[begin]��С

		//��Сֵ�±�(������󽻻�����)
		int minIndex = begin;
		//��Ӧ����Сֵ(���ڱȽ�)
		int min = v[minIndex];

		//����begin֮�����
		//����minС����¼�����±��ֵ
		for (int j = begin + 1; j < v.size(); ++j)
		{
			if (v[j] < min)
			{
				minIndex = j;
				min = v[j];
			}
		}

		//��ʱminIndexΪ��Сֵ�±�,�� ��Сֵλ�� �� beginλ�� ��ֵ������
		swap(v[minIndex], v[begin]);
	}
}

//adjust:Ҫ���µ�����λ�ã�adjustλ�ý������Ӻ��Һ��ӱ��붼�Ǵ��
//end���ѵ�Ԫ���±����ֵ[����ҿ�)
void adjustDown(vector<int>& v, int adjust, int end)
{
	//�������Ľ���к��ӣ��ſ������µ���
	while (adjust * 2 + 1 < end)
	{
		//�������ĺ���������
		int maxChild = adjust * 2 + 1;

		//����Һ��Ӵ����Ҵ�������
		if (maxChild + 1 < end && v[maxChild + 1] > v[maxChild])
		{
			++maxChild;
		}

		//������������С�����ĺ��ӣ���Ҫ���µ���������ֱ�ӽ���
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
	//1 ����(���µ�������) ����  �����һ����Ҷ�ӽ�㿪ʼ����
	//�����һ�����ĸ����
	for (int i = ((v.size() - 1) - 1) / 2; i >= 0; --i)
	{
		adjustDown(v, i, v.size());
	}

	//  2 �����Ѷ�Ԫ��ѡ�� + ����
	for (int i = v.size() - 1; i > 0; --i)
	{
		//��ѡ�������ֵ������ĩβ
		swap(v[i], v[0]);

		//��ʣ�µ��������ɶ�,
		adjustDown(v, 0, i); //����������ҿ����������i
	}
}

void bubbleSort(vector<int>& v)
{
	//ÿһ��ð�ݶ����ô��������е����ֵ�ŵ�ĩβ���������Ԫ����Ŀ-1
	//Ҫ����v.size() - 1��ð��
	for (int i = 0; i < v.size() - 1; ++i)//i��ʾ��ɵ�ð�ݴ���
	{
		//��ʶ�˴�ð���Ƿ��з�������
		bool flag = false;

		//����һ��ð��
		//begin��begin+1λ�õ�ֵ�Ƚϣ���Ľ������ұ�
		for (int begin = 0; begin < v.size() - 1 - i; ++begin)//���������е�ĩβ��ı�
		{
			if (v[begin] > v[begin + 1])
			{
				swap(v[begin], v[begin + 1]);
				flag = true;
			}
		}

		//���˴�ð��û�з���������˵���Ѿ�����
		if (flag == false)
			return;
	}
}

//����ȡ��,�����м�ֵ���±�
int getMidKeyi(const vector<int>& v, int begin, int end)
{
	int mid = (begin + end) / 2;

	if (v[begin] < v[mid])
	{
		if (v[mid] < v[end])
			return mid;
		//����midλ��Ϊ���ֵ
		else if (v[begin] < v[end])//�δ�ֵ��Ϊ�м�ֵ
			return end;
		else
			return begin;
	}
	else//v[begin] > v[mid]
	{
		if (v[end] > v[begin])
			return begin;
		//����beginλ��Ϊ���ֵ
		else if (v[mid] < v[end])//�Ҵδ�ֵ
			return end;
		else
			return mid;
	}
}

//���������ˣ�hoare�汾
//[begin, end]��Ҫ���е������������
int quickPartSortHoare(vector<int>& v, int begin, int end)
{
	//����ȡ��
	//int tmp = getMidKeyi(v, begin, end);
	//swap(v[begin], v[tmp]);

	//keyλ��
	int keyi = begin;
	//ѡ�����һ����Ϊkey
	int key = v[begin];

	while (begin < end)
	{
		//�����key���ұ�����(Ϊ�˱�֤����λ�õ�ֵ����keyС)

		//�ұ���С��v[end]���һֱ��ǰ��
		while (begin < end && v[end] >= key)
			--end;

		//����Ҵ�v[begin]С��һֱ������
		while (begin < end && v[begin] <= key)
			++begin;

		//���1��begin = end;
		//���2��v[begin] > key��v[end] < key��������ҵ���,�ұ��ҵ�С
		swap(v[begin], v[end]);
	}

	//���� keyλ�� �� ����λ�� ��ֵ
	swap(v[keyi], v[begin]);

	//����keyi�����ػ�׼ֵ���±�
	keyi = begin;
	return keyi;
}

//���������ˣ��ڿӷ�
int quickPartSortHole(vector<int>& v, int begin, int end)
{
	//����ȡ��
	//int tmp = getMidKeyi(v, begin, end);
	//swap(v[begin], v[tmp]);

	int key = v[begin];

	//��׼ֵ��λ���γɿ�
	int hole = begin;
	while (begin < end)
	{
		//�ұ���С
		while (begin < end && v[end] >= key)
			--end;
		//�ҵ��Ժ󣬰�ֵ����ɿ�λ��endλ���γ��µĿ�λ
		v[hole] = v[end];
		hole = end;

		//����Ҵ�
		while (begin < end && v[begin] <= key)
			++begin;
		//�ҵ��Ժ󣬰�ֵ����ɿ�λ��beginλ���γ��µĿ�λ
		v[hole] = v[begin];
		hole = begin;
	}

	//��������ڿ�λ
	v[hole] = key;
	return hole;
}

//���������ˣ�ǰ��ָ��汾
int quickPartSortPreCur(vector<int>& v, int begin, int end)
{
	//����ȡ��
	int tmp = getMidKeyi(v, begin, end);
	swap(v[begin], v[tmp]);

	//ѡ���׼ֵ
	int key = v[begin];

	//��ʼ��ǰ��ָ��
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
	//��ʱpreǰ�����(����preָ�����)����С�ڻ�׼ֵ������׼ֵ�⣩
	swap(v[pre], v[begin]);
	//�������׼ֵ��λ�þ���pre
	return pre;
}
void quickSortChild(vector<int>& v, int begin, int end)
{
	if (begin >= end)
		return;
	//����������ֻ��9����
	if (end - begin + 1 <= 9)
	{
		//дһ����[begin, end]������в�������ĺ���
		insertSort(v, begin, end);
		return;
	}
	//����������ѡһ��
	//int keyi = quickPartSortHoare(v, begin, end);
	//int keyi = quickPartSortHole(v, begin, end);

	//�ȴ��� ��׼ֵ������׼ֵ�ŵ���ȷλ��
	int keyi = quickPartSortPreCur(v, begin, end);

	//�����������������
	//�����䣺[begin, keyi - 1]
	//�����䣺[keyi + 1, end]
	quickSortChild(v, begin, keyi - 1);
	quickSortChild(v, keyi + 1, end);
}
void quickSortR(vector<int>& v)
{
	quickSortChild(v, 0, v.size() - 1);
}



//�ǵݹ�
void quickSortNotR(vector<int>& v)
{
	//�洢����
	stack<int> st;

	//[0, v.size() - 1]
	//ջ����ȳ����������� �����ұ�
	st.push(v.size() - 1);
	st.push(0);

	while (!st.empty())
	{
		//��ǰ�����ջ��׼������
		int left = st.top();
		st.pop();
		int right = st.top();
		st.pop();

		//����ǰ����Ļ�׼ֵ
		int keyi = quickPartSortPreCur(v, left, right);

		//����ǰ�����Ϊ ������ �� ������
		//[left,keyi - 1]  [keyi + 1, right]
		//��������Ҵ���һ������������ջ
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


//��������������[begin1, end1] [begin2, end2]�ϲ���һ�Σ�����tmp��
void singleMerge(vector<int>& v, int begin1, int end1, int begin2, int end2, int* tmp)
{
	int i = 0;

	//��һ�������ݷ���ͽ���
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (v[begin1] <= v[begin2])
			tmp[i++] = v[begin1++];
		else if (v[begin2] < v[begin1])
			tmp[i++] = v[begin2++];
	}

	//Ȼ�����һ������ʣ�����ݿ�����ȥ
	while (begin1 <= end1)
		tmp[i++] = v[begin1++];
	while (begin2 <= end2)
		tmp[i++] = v[begin2++];
}

//��������������[begin1, end1] [begin2, end2]�ϲ���һ�Σ�����tmp�У���ʼλ����pos
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

	//[begin1, end1]  [begin2, end2] ���εݹ飬������������
	mergeSortChild(v, begin1, end1, tmp);
	mergeSortChild(v, begin2, end2, tmp);

	//��������������鲢��tmp�У���ʼλ��Ϊpos
	singleMerge(v, begin1, end1, begin2, end2, pos, tmp);

	//���鲢�õ�tmp������ ������ԭ����
	while (begin <= end)
	{
		v[begin] = tmp[begin];
		++begin;
	}
}

void mergeSort(vector<int>& v)
{
	int* tmp = new int[v.size()];
	//����ұ�(Ҫ���й鲢���������)
	mergeSortChild(v, 0, v.size() - 1, tmp);
	delete[] tmp;
}

void mergeSortNotR(vector<int>& v)
{
	if (v.size() <= 1)
		return;

	int* tmp = new int[v.size()];

	//��ʶ����Ԫ��Ϊ1����й鲢
	int group = 1;

	while (group < v.size())
	{
		for (int i = 0; i < v.size(); i += group * 2/*������������*/)
		{
			//��һ��
			int begin1 = i;
			int end1 = i + group - 1;

			//�ڶ���
			int begin2 = i + group;
			int end2 = i + 2 * group- 1;

			int pos = i;

			//�߽�����

			//���end1Խ�磬����end1��ͬʱ˵���ڶ��鲻���ܴ���
			if (end1 >= v.size())
			{
				end1 = v.size() - 1;
				begin2 = v.size();
				end2 = v.size() - 1;
			}
			//begin2Խ�磬�ڶ������ݲ�����
			else if (begin2 >= v.size())
			{
				begin2 = v.size();
				end2 = v.size() - 1;
			}
			//ֻ��end2Խ�磬�����ڶ������ݼ���
			else if (end2 >= v.size())
			{
				end2 = v.size() - 1;
			}

			//�������н��ж�·�鲢
			singleMerge(v, begin1, end1, begin2, end2, pos, tmp);
		}
		//�����굱ǰ���е��飬���������� �鲢��Ľ��������tmp�У����������ԭ����		
		for (int j = 0; j < v.size(); ++j)
			v[j] = tmp[j];

		//����һ�����ݵĸ���
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

	//����һ������������ѡ��max
	for (auto x : v)
	{
		if (x > max)
			max = x;
	}

	//ֱ��ӳ��
	int* tmp = new int[max + 1];
	memset(tmp, 0, (max + 1) * sizeof(int));
	//tmp�±����v�г��ֵ�����
	//tmp�±�λ�õ�ֵ�����±����ֳ��ֵĴ���

	//����v��tmp��¼�������ֳ��ִ���
	for (int i = 0; i < v.size(); ++i)
		tmp[v[i]]++;


	int j = 0;
	//����tmp
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

	//����һ������������ѡ��max��min
	for (auto x : v)
	{
		if (x > max)
			max = x;
		if (x < min)
			min = x;
	}

	//���ӳ�� [min, max]
	int* tmp = new int[max - min + 1];
	//�±�0 ӳ�� min
	//�±�max - min ӳ�� max 
	memset(tmp, 0, (max - min + 1) * sizeof(int));

	//����v��tmp��¼�������ֳ��ִ���
	for (int i = 0; i < v.size(); ++i)
		tmp[v[i] - min]++;

	int j = 0;
	//����tmp
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
