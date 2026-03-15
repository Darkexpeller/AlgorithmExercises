// 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水
// 输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
// 输出：6
// 解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。
#include<stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int trap2(vector<int>& height) {
        //初始使用双指针来指定子容器边界，最左溢出，因此先找到第一个非0作为左边界,子容器边界外均为溢出
        int left = 0;
        int right = 1;
        int volume = 0;
        int n = height.size();
        int minheight = 0;
        while(left<n-2){
            
            for (int i = right; i < n;++i){
                if(height[right]<height[i])
                    right = i;
                if(height[right]>=height[left])
                    break;
            }
            //printf("right=%d \n", right);
            minheight = min(height[left], height[right]);
            for (int i = left; i < right;++i){
                //printf("%d \n", height[i]);
                if(height[i]<minheight)
                    volume += minheight - height[i];
            }
            left = right;
            right++;
        }

        return volume;
    }
    int trap(vector<int>& height) {
        //头尾双指针，高板可以给低板兜底，因此低板向内移动，并计算水量；
        int n = height.size();
        if(n<3)
            return 0;
        int left = 0;
        int right = n - 1;
        int left_max_index = left;
        int right_max_index = right;
        int volume = 0;
        while(left<right){
            if(height[left_max_index]<height[right_max_index]){
                volume += height[left_max_index] - height[left++];
            }else{
                volume += height[right_max_index] - height[right--];
            }
            if(height[left]>=height[left_max_index])
                left_max_index = left;
            if(height[right]>=height[right_max_index])
                right_max_index = right;
            
        }
        return volume;
        }
};

int main(){
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution s;
    auto ret = s.trap(height);
    printf("%d", ret);
}