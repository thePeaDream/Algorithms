class Solution {
public:
    //f(0) = 0 f(1) = 1
    //f(n) = f(n-1)+f(n-2)
    int fib(int n) 
    {
        if(n == 0) return 0;
        vector<int> dp;
        dp.resize(n+1);//多开一个空间，用于dp[n]
        dp[0] = 0;
        dp[1] = 1;
        //dp[n]就是f(n)的值,即第n个斐波那契数
        for(int i = 2; i < n+1; i++)
        {
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};
