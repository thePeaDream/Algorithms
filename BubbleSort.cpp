#include <vector>
using namespace std;
void BubbleSort(vector<int>& vet)
{
  for(int rank = 0; rank < vet.size()-1; rank++)//每一趟至少可以让一个数有序，所以最多只需vet.size()-1趟
  {
    //假设已经有序
    int flag = 1;
    
    //从头开始，相邻元素比较
    for(int pre = 0; pre < vet.size()-1-rank; pre++)
    {
      if(vet[pre] > vet[pre+1])
      {
        flag = 0;
        swap(vet[pre], vet[pre+1]);
      }
    }
  
    //若一趟下来没有比较，说明已经有序
    if(flag == 1)
        return;
  }
}

void BubbleSortReverse(vector<int>& vet)
{
  for(int rank = 0; rank < vet.size()-1; rank++)//每一趟至少可以让一个数有序，所以最多只需vet.size()-1趟
  {
    //假设已经有序
    int flag = 1;
    
    //从头开始，相邻元素比较
    for(int pre = 0; pre < vet.size()-1-rank; pre++)
    {
      if(vet[pre] < vet[pre+1])
      {
        flag = 0;
        swap(vet[pre], vet[pre+1]);
      }
    }
  
    //若一趟下来没有比较，说明已经有序
    if(flag == 1)
        return;
  }
}
