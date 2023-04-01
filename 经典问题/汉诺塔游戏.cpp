//给定3根柱子，A柱上有n个圆盘，从上到下记作0~n-1,上面圆盘一定比下面圆盘小
//将A柱上的盘子经B柱，移动到C柱，最少需要多少次?

//注意：一次只能移动一个盘子
//大盘子一定在小盘子下面

#include <iostream>
#include <vector>
using namespace std;
int movePlate(vector<int>& v1, vector<int>& v3, int n)
{
   if(n == 1)
   {
      v3.push_back(v1[0]);
      return 1;
   }

   vector<int> v2;
   v2.resize(n-1);
   int ret = 0;

   //把前n-1层看成一个整体，把他搬到v2
   ret += movePlate(v1, v2, n - 1);
   
   //把最后一层搬到v3
   v3.push_back(v1[n-1]);
   ret++;
   
   //最后再把v2中的n-1层搬到v3
   ret += movePlate(v2, v3, n-1);

   return ret;
}

int main()
{
    int n = 0;
    cout << "请输入圆盘数目：" << endl;
    cin >> n;
    vector<int> v1;
    vector<int> v3;
    v1.resize(n);
    for(int i = 0; i < v1.size(); i++)
        v1[i] = i+1;
    
    v3.resize(n);
    int ret = movePlate(v1,v3,n);
    cout << "最少需要" << ret << "次" << endl;
    return 0;
}
