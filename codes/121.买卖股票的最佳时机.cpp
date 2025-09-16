// For VSCode Coding
#include <bits/stdc++.h>
using namespace std;
//

/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 单指针扫描，储存当前最小值，对每个值进行判断
        int ans = 0;
        prices.push_back(INT_MIN);
        int cur_min = prices[0];
        for(int i = 1; i < prices.size() - 1; i++){
            if(prices[i] < cur_min){
                cur_min = prices[i];
                continue;
            }
            else {
                ans = max (ans, prices[i] - cur_min);
            }
        }
        return ans;
    }
};
// @lc code=end

