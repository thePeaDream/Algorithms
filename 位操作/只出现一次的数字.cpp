class Solution {
public:
    //n^n = 0;
    //n^0 = n
    int singleNumber(vector<int>& nums) 
    {
        //所有数字按位异或
        int init = nums[0];
        for(int i = 1; i < nums.size();i++)
        {
            init ^= nums[i];
        }
        return init;
    }
};
