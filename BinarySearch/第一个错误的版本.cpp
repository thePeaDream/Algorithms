class Solution {
public:
    int firstBadVersion(int n)//相当于二分查找，找第一个出错的版本
    {
        if(isBadVersion(1))//特殊处理
            return 1;

        int left = 1;
        int right = n;
        while(left <= right)
        {
            int mid = (right - left)/2 + left;
            if(isBadVersion(mid)&&isBadVersion(mid-1))
            {
                //如果这个版本错误，并且上一个版本也是错的，查找范围缩小至[left, mid - 1]
                right = mid-1;
            }
            else if(isBadVersion(mid)&&!isBadVersion(mid-1))
            {
                //如果该版本错误，上一个版本正确，找到第一个出错的版本
                return mid;
            }
            else
            {
                //如果这个版本正确，查找范围缩小至[mid+1, right]
                left = mid+1;
            }
        }
        return -1;
    }
};
