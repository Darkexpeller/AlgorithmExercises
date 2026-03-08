//189-rotate.cpp
/*
g++ 189-rotate.cpp -o 189-rotate
189.轮转数组
给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。

*/


#include<iostream>
#include<vector>
#define SWAP(a, b) do { int temp = a; a = b; b = temp; } while (0)
using namespace std;

class Solution
{
public:
    void rotete_1(vector<int>& nums,int k)//拷贝数组
    {
        auto nums_backup = nums;
        k = k % nums.size();
        for (int i = 0; i < nums_backup.size();i++)
        {
            nums[(i + k) % nums.size()] = nums_backup[i];
        }
    }
    void rotete_2(vector<int>& nums,int k)//原地旋转
    {
//反转整个数组。
//反转前 k 个元素。
// 反转剩余部分的元素。
        k = k % nums.size();
        for (int i = 0; i < nums.size() / 2;++i)
        {
            SWAP(nums[i], nums[nums.size() - i - 1]);
        }
        for (int i = 0; i < k/2;++i)
        {
            SWAP(nums[i], nums[k - i - 1]);
        }
        for (int i = k; i <= (k+nums.size()-1)/2;++i)
        {
            SWAP(nums[i], nums[nums.size() -1-(i-k)]);
        }
    }
};