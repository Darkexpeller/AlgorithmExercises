//88-join-array.cpp
/*
g++ 88-join-array.cpp -o 88-join-array
给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。

请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。

注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。
为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，
应忽略。nums2 的长度为 n 。
*/
#include<iostream>
#include<vector>
#define SWAP(a, b) do { int temp = a; a = b; b = temp; } while (0)

using namespace std;

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // 从后向前合并
        int p1 = m - 1; // 指向 nums1 的最后一个有效元素
        int p2 = n - 1; // 指向 nums2 的最后一个元素
        int p = m + n - 1; // 指向 nums1 的末尾位置

        while (p1 >= 0 && p2 >= 0) {
            if (nums1[p1] > nums2[p2]) {
                nums1[p--] = nums1[p1--]; // nums1 的元素更大
            } else {
                nums1[p--] = nums2[p2--]; // nums2 的元素更大
            }
        }

        // 如果 nums2 还有剩余
        while (p2 >= 0) {
            nums1[p--] = nums2[p2--];
        }

    }
};

int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    Solution s1;
    s1.merge(nums1, 3, nums2, 3);
    for (int i = 0; i < nums1.size(); i++) {
        cout << nums1[i] << " ";
    }
    return 0;
}
