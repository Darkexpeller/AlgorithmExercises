// 给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
// 输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
// 输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
// 解释：
// 在 strs 中没有字符串可以通过重新排列来形成 "bat"。
// 字符串 "nat" 和 "tan" 是字母异位词，因为它们可以重新排列以形成彼此。
// 字符串 "ate" ，"eat" 和 "tea" 是字母异位词，因为它们可以重新排列以形成彼此。
#include<vector>
#include <cstdint>
#include<stdio.h>
#include<string>
#include <unordered_map>
#include<iostream>
#include <numeric>
#include<array>
using namespace std;
class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        if(strs.size()==0)
            return ret;
        auto arrayHashFun = [fn = hash<int>{}](const array<uint8_t, 26> &arr) -> size_t
        {
            return accumulate(arr.begin(), arr.end(), 0u,[&](size_t acc,uint8_t num){
                return acc ^ (fn((int)num) + 0x9e3779b9 + (acc << 6) + (acc >> 2));
            });
        };
        unordered_map<array<uint8_t, 26>, vector<string>, decltype(arrayHashFun)> StringMap(0,arrayHashFun);
        for (int i = 0; i < strs.size();++i){
            array<uint8_t, 26> Conunter={0};
            
            for (int j = 0; j < strs[i].size();++j){
                Conunter[strs[i][j] - 'a']++;
            }
            StringMap[Conunter].emplace_back(std::move(strs[i]));
        }
        
        for (auto it = StringMap.begin(); it != StringMap.end(); ++it) {
            ret.emplace_back(std::move(it->second));
            
        }
        return ret;
    }
};
class LeeCodeSolution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 自定义对 array<int, 26> 类型的哈希函数
        auto arrayHash = [fn = hash<int>{}] (const array<int, 26>& arr) -> size_t {
            return accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num) {
                return (acc << 1) ^ fn(num);
            });
        };

        unordered_map<array<int, 26>, vector<string>, decltype(arrayHash)> mp(0, arrayHash);
        for (string& str: strs) {
            array<int, 26> counts{};
            int length = str.length();
            for (int i = 0; i < length; ++i) {
                counts[str[i] - 'a'] ++;
            }
            mp[counts].emplace_back(str);
        }
        vector<vector<string>> ans;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            ans.emplace_back(it->second);
        }
        return ans;
    }
};


int main(){
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution s;
    auto result=s.groupAnagrams(strs);
    for (int i = 0; i < result.size();++i){
        for (int j = 0; j < result[i].size(); ++j){
            std::cout << result[i][j]<<" ";
        }
        std::cout << std::endl;
    }
    printf("\n");
}