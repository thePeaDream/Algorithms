#include <iostream>
#include <vector>
using namespace std;

void InsertSort(vector<int>& v)
{
  //将当前遍历到的数字插入到有序队列中
  for(int i = 1; i < v.size(); i++)
  {
      int num = v[i];
      int insertPosition = i - 1;
      //最后要插入到insertPosition+1
      while(insertPosition >= 0)
      {
        if(num < v[insertPosition])
        {
          v[insertPosition+1] = v[insertPosition];
          insertPosition--;
        }
        else
          break;
      }
      v[insertPosition+1] = num;
  }
}

  
void InsertSortReverse(vector<int>& v)
{
  //将当前遍历到的数字插入到有序队列中
  for(int i = 1; i < v.size(); i++)
  {
      int num = v[i];
      int insertPosition = i - 1;
      //最后要插入到insertPosition+1
      while(insertPosition >= 0)
      {
        if(num > v[insertPosition])
        {
          v[insertPosition+1] = v[insertPosition];
          insertPosition--;
        }
        else
          break;
      }
      v[insertPosition+1] = num;
  }
}
