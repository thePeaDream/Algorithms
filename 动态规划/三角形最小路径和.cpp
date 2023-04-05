class Solution {
public:
    //dp[0][0] - 到triangle[0][0]的最小路径和 
    //dp[1][0] - 到triangle[1][0]的最小路径和 = dp[0][0] + tri[1][0]
    //dp[1][1] - 到triangle[1][1]的最小路径和 = dp[0][0] + tri[1][1]
    //到triangle[row][col]的最小路径和 = min(dp[row-1][col]，dp[row-1][col-1])
    //+triangle[row][col]

    int minimumTotal(vector<vector<int>>& triangle) 
    {
        if(triangle.size() == 1)//只有一行
            return triangle[0][0];
        //创建dp数组同时给初始值
        vector<vector<int>> dp = triangle;
        dp[0][0] = triangle[0][0];
        dp[1][0] = dp[0][0] + triangle[1][0];
        dp[1][1] = dp[0][0] + triangle[1][1];
        
        //利用上述公式，完善dp数组的值
        for(int row = 2; row < dp.size(); row++)
        {
            //到triangle[row][0]的路径是唯一的
            dp[row][0] = dp[row-1][0]+triangle[row][0];

            for(int col = 1; col < dp[row].size(); col++)
            {
                //注意当col == dp[row].size-1时，就是本行最后一个数 dp[row-1][col]会非法
                if(col < dp[row-1].size())
                    dp[row][col] = 
                    min(dp[row-1][col], dp[row-1][col-1])+triangle[row][col];
                else
                dp[row][col] = dp[row-1][col-1]+triangle[row][col];
            }
        }

        //在dp数组最后一行选出minPath
        int minVal = dp[dp.size()-1][0];
        for(int col = 1; col < dp[dp.size()-1].size(); col++)
        {
            if(dp[dp.size()-1][col] < minVal)
                minVal = dp[dp.size()-1][col];
        }
        return minVal;
    }
};
