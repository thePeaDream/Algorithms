class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        //特殊情况
        if(s1.size() > s2.size())
            return false;

        //滑动窗口长度
        int s1Length = s1.size();
        
        //arr1映射s1的出现字符
        int arr1[26] = { 0 };
        //arr2映射窗口的出现字符
        int arr2[26] = { 0 };

        //让窗口保持s1Length的大小
        int left = 0;
        int right = s1Length - 1;

        //初始的窗口arr2 和 arr1
        for(int i = 0; i < s1Length; i++)
        {
            arr1[s1[i] - 'a']++;//s1的出现字符
            arr2[s2[i] - 'a']++;//窗口的初始出现字符
        }

        while(right < s2.size())
        {
            int flag = 1;//假设本次匹配成功
            for(int i = 0; i < 26; i++)
            {
                if(arr1[i] != arr2[i])//本次匹配失败
                {
                    flag = 0;
                    break;
                }
            }
            if(flag == 1) return true;

            //匹配失败，滑动窗口右移,更新滑动窗口里的出现字符
            arr2[s2[left] - 'a']--;
            left++;

            right++;
            if(right < s2.size())
                arr2[s2[right] - 'a']++;
        }
        return false;
    }
};
