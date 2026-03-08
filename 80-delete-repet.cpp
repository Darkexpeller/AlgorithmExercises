// 80-delete-repet.cpp
/*
g++ 80-delete-repet.cpp -o 80-delete-repet
给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使得出现次数超过两次的元素只出现两次 ，返回删除后数组的新长度。

不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if(nums.size()<2)
            return nums.size();

        int pcurrent = 2; // 第三个位置开始写入
        for (int pquick = 2; pquick < nums.size(); ++pquick) {
            if (nums[pquick] != nums[pcurrent - 2]) { // 当前值与结果数组倒数第二个值不同
                nums[pcurrent++] = nums[pquick];     // 写入当前值
            }
        }
        return pcurrent; // 返回新数组长度

        // int pslow = 0; // pslow代表k的位置，1，2号指针是为了前移
        // int pquick = 0;
        // int pcurrent = 0; // 主指针所在位置，为即将改写的位置
        
        // while (pquick < nums.size())
        // {
        //     if (nums[pquick] != nums[pslow]) // 当前走出同数范围
        //     {
        //         if (pquick - pslow <= 2)
        //         {
        //             while (pslow < pquick)
        //             {
        //                 nums[pcurrent++] = nums[pslow++];
        //             }
        //         }
        //         else
        //         {
        //             nums[pcurrent++] = nums[pslow++];
        //             nums[pcurrent++] = nums[pslow];
        //             pslow = pquick;
        //         }
        //     }
        //     else
        //     { // 如果相同
        //         if (pquick + 1 < nums.size())//如果还没到最后一个
        //         {
        //             pquick++;
        //         }
        //         else//已经是最后一个元素
        //         {
                    
        //             if ((pquick - pslow) < 2)
        //             {
                        
        //                 while (pslow <= pquick)
        //                 {
        //                     nums[pcurrent++] = nums[pslow++];
        //                 }
        //             }
        //             else
        //             {
        //                 nums[pcurrent++] = nums[pslow++];
        //                 nums[pcurrent++] = nums[pslow];
        //                 pslow = pquick;
        //             }
        //             break;
        //         }
                
        //     }
        // }
        
        // return pcurrent ;
    }
};

int main()
{
    vector<int> nums1 = {1};

    Solution s1;
    cout << s1.removeDuplicates(nums1) << endl;
    for (int i = 0; i < nums1.size(); i++)
    {
        cout << nums1[i] << " ";
    }
    return 0;
}
