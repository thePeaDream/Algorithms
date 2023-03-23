class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int left = 0;
        int right = nums.size()-1;
        while(left <= right)
        {
            int mid = (right-left)/2+left;
            if(target < nums[mid])
            {
                //缩小范围，在[left, mid-1]找
                right = mid - 1;
            }
            else if(target == nums[mid])
                return mid;
            else if(target > nums[mid])
            {
                //缩小范围，在[mid+1, right]找
                left = mid+1;
            }
        }
        return -1;

    }
};
