// 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

// 请注意 ，必须在不复制数组的情况下原地对数组进行操作。

// 示例 1:

// 输入: nums = [0,1,0,3,12]
// 输出: [1,3,12,0,0]
// 示例 2:

// 输入: nums = [0]
// 输出: [0]
// 提示:

// 1 <= nums.length <= 104
// -231 <= nums[i] <= 231 - 1
 
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

#define SWAP(a, b)       \
    do {                 \
        int __temp = (b);\
        (b) = (a);       \
        (a) = __temp;    \
    } while (0)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int start = -1;
        int nonzero = 0;
        for (int i = 0; i < nums.size();++i){
            if(nums[i]==0){
                start = i;
                break;
            }
        }
        if(start==-1)
            return;
        for (int i = start+1;i < nums.size();++i){
            if(nums[i]!=0){
                nonzero = i;
                break;
            }
        }
        if(nonzero==0)
            return;
        for (;nonzero<nums.size();++start){
           // printf("%d %d\n", start, nonzero);
            nums[start] = nums[nonzero++];
            for (int j = nonzero;j < nums.size();++j){
            if(nums[j]!=0){
                nonzero = j;
                break;
            }
        
        }
        
        }
        for(;start < nums.size();++start){
            nums[start] = 0;
        }
    }
};  


int main(){
    vector<int> nums = {0,1,0,3,12};
    Solution s;
    s.moveZeroes(nums);
    for(int num:nums){
        printf("%d ", num);
    }
}