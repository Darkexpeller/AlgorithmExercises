/*
赎金信
给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。

如果可以，返回 true ；否则返回 false 。

magazine 中的每个字符只能在 ransomNote 中使用一次。
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
    public:
        bool canConstruct(string ransomNote, string magazine) {
            vector<int> count(26);
            for(auto& c:magazine)
            {
                count[c-'a']++;
            }

            for(auto& c:ransomNote)
            {
                if(count[c-'a']>0)
                {
                    count[c-'a']--;
                }
                else
                {
                    return false;
                }
            }
            return true;

        }
    };