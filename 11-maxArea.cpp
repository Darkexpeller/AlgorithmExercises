// 给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。

// 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

// 返回容器可以储存的最大水量。

// 说明：你不能倾斜容器。
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
/*思路：
    暴力组合有C(2,n)个，双指针初始在左右两端，每次将短板往里移。迭代会排除掉n-1 n-2 n-3....1个不优状态
    这样当左右指针相遇时刚好排除掉了C(2,n)个状态。该贪心策略可行。
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size()==0)
            return 0;
        else if(height.size()==1)
            return height[0];
        int left = 0;
        int right= height.size() - 1;
        int maxWater=0 ;
        while(left!=right){
            maxWater = max((min(height[left], height[right])) * (right - left),maxWater);
            if(height[left]<=height[right]) //将短板往里面移。
                ++left;
            else
                --right;
        }
        return maxWater;
    }
};

int main(){
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution s;
    printf("%d\n", s.maxArea(height));
}