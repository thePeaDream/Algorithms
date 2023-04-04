class Solution {
public:
    int hammingWeight(uint32_t n) 
    {
        int num = 0;
        for(int i = 0; i < 32; i++)
        {
            if(( (n>>i)&1 )== 1) //(n>>i)&&1就是第i+1位上的二进制数
                num++;
        }    
        return num;
    }
};
