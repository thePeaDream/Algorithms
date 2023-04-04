class Solution {
public:
    //假设走到第n阶楼梯有dp[n]种 
    //走到第n-1阶楼梯有dp[n-1]种……
    //走到第1阶楼梯有dp[1] = 1  dp[2] = 2

    //dp[n] = dp[n-1]+dp[n-2]
    int climbStairs(int n) 
    {
        if(n == 1 || n == 2)
            return n;

        vector<int> dp;
        dp.resize(n+1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; i++)
        {
            dp[i] = dp[i-1]+dp[i-2]; 
        }
        return dp[n];

    }
};
