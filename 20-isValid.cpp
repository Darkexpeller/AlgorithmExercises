/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        vector<char> cStack{0};
        int size = 0;
        for (char c : s)
        {
            if ((c == '(' || c == '{' || c == '['))
            {
                cStack.push_back(c);
            }
            switch (c)
            {
            case ')':
                if (*(cStack.end() - 1) == '(')
                {
                    cStack.pop_back();
                }
                else
                {
                    return false;
                }
                break;
            case '}':
                if (*(cStack.end() - 1) == '{')
                {
                    cStack.pop_back();
                }
                else
                {
                    return false;
                }
                break;
            case ']':
                if (*(cStack.end() - 1) == '[')
                {
                    cStack.pop_back();
                }
                else
                {
                    return false;
                }
                break;
            default:
                break;
            }
        }
        if (cStack.size() > 1)
        {
            return false;
        }
        return true;
    }
};