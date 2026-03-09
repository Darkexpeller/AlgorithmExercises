// 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

// 你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。

// 你可以按任意顺序返回答案。
#include<stdio.h>
#include <vector>
#include<map>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map <int,int> map;
        for (int i = 0; i < nums.size();++i){
            auto iter = map.find(target - nums[i]);
            if(iter!=map.end()){//如果余数在map中(已被访问过 <==>在数组中)
                return {iter->second, i};
            }
            map.insert(pair<int, int>(nums[i], i)); // 如果没找到匹配对，就把访问过的元素和下标加入到map中
        }
        return {};
    }
};

int main(){
    vector<int> nums = {2, 7, 11, 15};
    Solution s;
    auto result=s.twoSum(nums, 17);
    for (int i = 0; i < result.size();++i){
        printf("%d ", result[i]);
    }
    printf("\n");
}