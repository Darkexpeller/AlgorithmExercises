//121-maxProfit.cpp
/*
买卖股票的最佳时机
给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。

你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。

返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int>& prices)//贪心算法
    {
        int minPrice = INT_MAX;
        int maxprofit = 0;
        for(int num:prices)
        {
            if(num<minPrice)
            {
                minPrice = num;
            }
            else
            {
                maxprofit = max(maxprofit, num - minPrice);
            }
        }
        return maxprofit;
    }
    int maxProfit_2(vector<int>& prices)//动态规划
    {
        vector<int> dp(prices.size(), 0);
        int minPrice = prices[0];
        for (int i = 1; i < prices.size();++i)
        {
            minPrice = min(minPrice, prices[i]);
            dp[i] = max(dp[i - 1], prices[i] - minPrice);
        }
        return dp[prices.size()-1];
    }
};  