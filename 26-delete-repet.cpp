//26-delete-repet.cpp
/*
g++ 26-delete-repet.cpp -o 26-delete-repet
给你一个 非严格递增排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。然后返回 nums 中唯一元素的个数。

考虑 nums 的唯一元素的数量为 k ，你需要做以下事情确保你的题解可以被通过：

更改数组 nums ，使 nums 的前 k 个元素包含唯一元素，并按照它们最初在 nums 中出现的顺序排列。nums 的其余元素与 nums 的大小不重要。
返回 k 
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    int removeDuplicates(vector<int>& nums) {
        int pquick, pslow = 0;
        pquick = 1;
        while (pquick < nums.size())
        {
            if(nums[pquick]!=nums[pslow])
            {
                nums[++pslow] = nums[pquick++];
            }
            else{
                ++pquick;
            }
        }
        return pslow + 1;
    }
};

int main() {
    vector<int> nums1 = {1, 2, 3,3,4,4,4,5,6};

    Solution s1;
    cout << s1.removeDuplicates(nums1) << endl;
    for (int i = 0; i < nums1.size(); i++) {    
        cout << nums1[i] << " ";
    }
    return 0;
}
