class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {
        //题意返回第一个大于或等于target的下标 
        int left = 0;
        int right = nums.size();//若target大于所有值，需要插入到下标为nums.size()的位置
        
        //初始搜索插入范围
        while(left < right)
        {
            int mid = (right-left)/2+left;
            if(nums[mid] >= target)
            {
                //下标为mid的值也可能是第一个>=target，所以搜索范围[left, mid]
                right = mid;
            }
            else if(nums[mid] < target)
            {
                //mid之前包括mid下标的值一定不满足搜索要求，[mid+1, right]
                left = mid+1;
            }
        }
        return left;
    }
};
