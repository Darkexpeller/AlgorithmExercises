// 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
// 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
// 示例 1：
// 输入：nums = [100,4,200,1,3,2]
// 输出：4
// 解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。

// 示例 2：
// 输入：nums = [0,3,7,2,5,8,4,6,0,1]
// 输出：9

// 示例 3：
// 输入：nums = [1,0,1,2]
// 输出：3


#include<vector>
#include <cstdint>
#include<stdio.h>
#include<string>
#include <unordered_map>
#include<iostream>
#include <numeric>
#include<array>
#include <utility>
#include <algorithm>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        unordered_set<int> numSet;
        for(int num:nums){
            numSet.insert(num);
        }
        int MaxConsecutiveLengths=1;
        for (auto it=numSet.begin(); it!=numSet.end();++it){
            if(numSet.find(*it-1)!=numSet.end())
                continue;
            int first = *it;
            int second = *it;

            
            for (int i=second+1;;++i){
                if(numSet.find(i)==numSet.end())
                    break;
                second = i;
            }
            if(MaxConsecutiveLengths< second-first+1)
                MaxConsecutiveLengths = second - first + 1;
        }
        return MaxConsecutiveLengths;
    }
};

int main(){

    vector<int> nums = {100,4,200,1,3,2};
    Solution s;
    auto result=s.longestConsecutive(nums);
    printf("%d\n",result);

}