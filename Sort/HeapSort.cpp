#include <iostream>
#include <vector>
using namespace std;


//begin:从哪里开始向上调整
//前提：前面的所有结点已经构成大堆
void AdjustUp(vector<int>& vec, int begin)
{
  int parent = (begin-1)/2;
  int pendingAdjust = begin;//待调整的结点,只会影响到它的祖先结点
  while(pendingAdjust > 0)
  {
    if(vec[parent] < vec[pendingAdjust])//若待调整结点比父亲结点大，交换满足大堆条件
      swap(vec[parent],vec[pendingAdjust]);
    else//否则该结点调整完毕
      return;
    //每调整一次就更新 待调整结点 的下标
    pendingAdjust = parent;
    parent = (pendingAdjust - 1)/2;
  }
}


//begin:从哪里开始向下调整
//end: 最多向下调整到哪里       左闭右开
//前提：左子树 和 右子树 都是大堆
void AdjustDown(vector<int>& vec, int begin, int end)
{
  int pendingAdjust = begin;
  int maxChild = 2*pendingAdjust+1;//假设最大结点是左孩子
  while(2*pendingAdjust+1 < end)//当待调整结点没有孩子时，调整结束
  {
    //先找出最大的孩子
    
    //如果右孩子存在且大于左孩子
    if(maxChild + 1 < end && vec[maxChild] < vec[maxChild+1])
      maxChild++;

    //比较不满足大堆条件，交换
    if(vec[maxChild] > vec[pendingAdjust])
      swap(vec[maxChild],vec[pendingAdjust]);
    else//否则该结点调整完成
      return;
    //每调整一次就更新 待调整结点 的下标
    pendingAdjust = maxChild;
    maxChild = 2*pendingAdjust+1;
  }
}

//堆排序:以升序为例 ——建大堆
void HeapSort(vector<int>& vec)
{
  //第一步：用数组建堆
  
  //向上调整算法建堆
  int num = vec.size();
  for(int i = 1;i < num;i++)
  {
      AdjustUp(vec, i);    
  }

  //向下调整建堆
  

  //通过选出最大的数放到尾部，实现升序
  //每次选数后，剩下的数用向下调整算法，重新调成大堆

  int tail = vec.size();//尾部在不断更新
  while(tail > 1) //当tail == 1时，说明只剩下一个数要排序
  {
    //选出最大的数(堆顶)放到尾部
    swap(vec[0], vec[tail-1]);

    //更新尾部(或者说要排序的数减1)
    tail--;
    
    //选数后，剩下的数用向下调整算法，重新调成大堆
    AdjustDown(vec, 0, tail);//细节：左闭右开
  }
}
