//圆桌上围坐着2n个人。
//其中n个人是好人,另外n个人是坏人。从第一个人开始数数,数到第m个人,立即赶走该人;然后从被赶走的人之后开始数数,再将数到的第m个人赶走……依此方法不断赶走围坐在圆桌上的人。
//预先应如何安排这些好人与坏人的座位,能使得在赶走n个人之后,圆桌上围坐的剩余的n个人全是好人?
#include <vector>
#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cout << "请输入围坐的人数n，总围坐的人数为2n:"<< endl;
    cin >> n;
    vector<int> v;
    v.resize(2*n);
    for(int i = 0; i < 2 * n; i++)
       v[i] = 1;
    //1表示好人，0表示坏人
    
    //数到第m个人一定为坏人
    int m = 0;
    cout << "请输入第一个坏人的编号"<<endl;
    cin >> m;
    
    //下标为(m - 1)%(2*n)坏人
    int mInit = m;
    //先安排坏人的座位，剩下全是好人
    for(int i = 0; i < n ; i++)
    {
      v[(m-1)%(2*n)] = 0;
      m += mInit;//从被赶走的人之后开始数m个 因为m发生改变，所以用要把m初始值记录下来
    }
    
    for(int i = 0; i < 2*n; i++)
    {
      cout << v[i];
    }
    cout << endl;
    
    
    return 0;
}
