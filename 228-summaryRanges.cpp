/*给定一个  无重复元素 的 有序 整数数组 nums 。

返回 恰好覆盖数组中所有数字 的 最小有序 区间范围列表 。也就是说，nums 的每个元素都恰好被某个区间范围所覆盖，并且不存在属于某个范围但不属于 nums 的数字 x 。

列表中的每个区间范围 [a,b] 应该按如下格式输出：

"a->b" ，如果 a != b
"a" ，如果 a == b
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include<string>
using namespace std;

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> ans;
        vector<int> NumStack;
        for (int i = 0; i < nums.size(); ++i)
        {
            // cout<<NumStack.size()<<" "<<endl;

            switch (NumStack.size())
            {
            case 0:
                NumStack.push_back(nums[i]);
                break;

            case 1:
                if (nums[i] <= NumStack[0] + 1)
                {

                    NumStack.push_back(nums[i]);
                }

                else
                {
                    ans.push_back(to_string(NumStack[0]));
                    NumStack.clear();
    
                    NumStack.push_back(nums[i]);
                }
                break;
            case 2:
                if (nums[i] <= NumStack[1] + 1)
                {

                    NumStack[1] = nums[i];
                }
                else
                {
                    ans.push_back(to_string(NumStack[0]) + string("->") + to_string(NumStack[1]));
                    NumStack.clear();

                    NumStack.push_back(nums[i]);
                }

                break;
            default:
                break;
            }
        }

        if (NumStack.size() == 1)
            ans.push_back(to_string(NumStack[0] ));
        if (NumStack.size() == 2)
            ans.push_back(to_string(NumStack[0]) + string("->") + to_string(NumStack[1]));
        return ans;
    }

    vector<string> summaryRanges_2(vector<int> &nums)
    {
        vector<string> ans;
        int i=0;
        int low;
        string temp;
        int n=nums.size();
    }
};

int main()
{
    vector<int> nums = {0, 2, 3, 4, 6, 8, 9};
    Solution s;
    vector<string> ans = s.summaryRanges(nums);
    for (string S : ans)
    {
        cout << S << " ";
    }
}