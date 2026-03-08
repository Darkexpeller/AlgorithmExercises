//27-delete-element.cpp
/*
g++ 27-delete-element.cpp -o 27-delete-element
./27-delete-element
给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素。元素的顺序可能发生改变。
然后返回 nums 中与 val 不同的元素的数量。

假设 nums 中不等于 val 的元素数量为 k，要通过此题，您需要执行以下操作：

更改 nums 数组，使 nums 的前 k 个元素包含不等于 val 的元素。nums 的其余元素和 nums 的大小并不重要。
返回 k。
*/

#include<iostream>
#include<vector>
#define SWAP(a, b) do { int temp = a; a = b; b = temp; } while (0)
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size()==0)
        {
            return 0;
        }
        int p1 = 0;
        int p2 = nums.size()-1;
        int k = 0;
        while (p1 < p2)
        {
            while (nums[p2] == val) // 从后到前找第一个非val
            {
                p2--;
                if(p1==p2)
                    goto there;
                
            }
            while(nums[p1]!=val)//找到第一个val
            {
                p1++;
                if(p1==p2)
                    goto there;
            }
            

            nums[p1++] = nums[p2];
            nums[p2--] = val;
        }
there:
        if(nums[p2]==val) //如果最后p2指向的值依然等于val，则p2指向筛选后的第一个val，k=p2
        {
            return p2;
        }
        return p2+1; //p2指向的为筛选后的最后一个非val
    }
};