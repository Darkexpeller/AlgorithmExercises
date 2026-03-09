// 给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
// 输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
// 输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
// 解释：
// 在 strs 中没有字符串可以通过重新排列来形成 "bat"。
// 字符串 "nat" 和 "tan" 是字母异位词，因为它们可以重新排列以形成彼此。
// 字符串 "ate" ，"eat" 和 "tea" 是字母异位词，因为它们可以重新排列以形成彼此。
#include<vector>
#include<stdio.h>
#include<string>
#include <unordered_map>
#include<iostream>
using namespace std;
class Solution {
public:
    bool isAnagram(vector<int>& s,vector<int>& t){
        //int CharConunter[26];
        // for (int i = 0; i < s.size();++i){
        //     CharConunter[s[i] - 'a']++;
        // }
        for (int i = 0; i < 26;i++){
            if(s[i]!=t[i])
                return false;
        }
        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        if(strs.size()==0)
            return ret;
        vector<vector<int> *> CharConunters(strs.size());
        for (int i = 0; i < strs.size();++i){
            vector<int> *Conunter=new vector<int>(26);
            
            for (int j = 0; j < strs[i].size();++j){
                (*Conunter)[strs[i][j] - 'a']++;
            }
            CharConunters[i]=Conunter;
        }
        
        vector<int> HasGrouped(strs.size());
        for (int i = 0; i < strs.size();++i){
            if(HasGrouped[i]==1)
                continue;
            HasGrouped[i] = 1;
            vector<string> group;
            group.push_back(strs[i]);
            for (int k = i + 1; k < strs.size();++k){
                if(HasGrouped[k]==0 && isAnagram(*CharConunters[i],*CharConunters[k])){
                    group.push_back(strs[k]);
                    HasGrouped[k] = 1;
                }
            }
            ret.push_back(group);
        }
        return ret;
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