class Solution {
public:
    //dp[1] = nums[0] - 只有一个房屋情况下，能偷到的最大金额
    //dp[2] = max(nums[0],nums[1]) -两个房屋
    //k间房屋，
    //如果偷第k间房屋，就不能偷第k-1间屋子
    //此时能偷到的最大金额为 前(k-2)间屋子里能偷到的最大金额+第k间屋子里的金额

    //如果不偷第k间房屋
    //此时能偷到的最大金额为 前(k-1)间屋子里能偷到的最大金额

    //dp[k] =max( dp[k-2] + nums[k-1],   dp[k-1] ); 
    int rob(vector<int>& nums) 
    {
        if(nums.size() == 1)
            return nums[0];

        vector<int> dp;
        dp.resize(nums.size()+1);
        dp[0] = 0;
        dp[1] = nums[0];
        dp[2] = max(nums[0],nums[1]);
        for(int i = 3; i < nums.size()+1; i++)
        {
            dp[i] = max(dp[i-2]+nums[i-1],dp[i-1]);
        }
        return dp[nums.size()];
    }
};
