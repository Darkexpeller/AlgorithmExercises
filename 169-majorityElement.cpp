#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution
{
public:
    int majorityElement(vector<int>& nums) {//使用摩尔投票法
        int candidate = 0, count = 0;
        for(int num:nums)
        {
            if(count==0)
            {
                candidate = num;
                count=1;
            }
            else
            {
                count += (num == candidate) ? 1 : -1;
            }
        }
        return candidate;
    }
};