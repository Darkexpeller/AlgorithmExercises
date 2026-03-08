/*  45-canJump-2.cpp
给定一个长度为 n 的 0 索引整数数组 nums。初始位置为 nums[0]。

每个元素 nums[i] 表示从索引 i 向后跳转的最大长度。换句话说，如果你在 nums[i] 处，你可以跳转到任意 nums[i + j] 处:

0 <= j <= nums[i] 
i + j < n
返回到达 nums[n - 1] 的最小跳跃次数。生成的测试用例可以到达 nums[n - 1]。
*/



#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution
{
public:

    int jump(vector<int>& nums)
    {
        if(nums.size()==1)
        {
            return 0;
        }
        int MaxStepTo=nums[0];
        int Maxindex=0;
        int count=0;
        int TempMaxStepTo=MaxStepTo;
        int TempIndex=0;

        while(true)
        {
            if(MaxStepTo>=nums.size()-1)
                return ++count;
            for(int i=Maxindex;i<=MaxStepTo;++i)
            {
                if((nums[i]+i)>TempMaxStepTo)
                {
                    TempMaxStepTo=nums[i]+i;
                    TempIndex=i;
                }
            }
            MaxStepTo=TempMaxStepTo;
            Maxindex=TempIndex;
            count++;
        }
        return count;
    }
};