class Solution {
public:
    //dp[0] = cost[0]; 到第0个台阶的最小花费
    //dp[1] = cost[1]; 到第1个台阶的最小花费
    //dp[2] = cost[2] + min(dp[0], dp[1]);
    
    //dp[i] = cost[i] + min(dp[i-1], dp[i]);
    //到第i个台阶的最小花费 = 到前两个台阶的最小花费取最小值 + 当前台阶花费
    int minCostClimbingStairs(vector<int>& cost) 
    {
        //直接在楼梯顶部
        if(cost.size() == 1)
            return 0;

        int n = cost.size();
        vector<int> dp(n+1,0);
        //dp[n] = min(dp[n-1],dp[n-2]) 因为在楼梯顶部不需要支付费用
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2; i < n; i++)
        {
            dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
        }
        dp[n] = min(dp[n-1],dp[n-2]);
        return dp[n];
    }
};
