// For VSCode Coding
#include <bits/stdc++.h>
using namespace std;
//

/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution{
public:
    // 详细的题解写在 Luogu P1020 导弹拦截了
    // 转一个讲解的比较清晰的 Blog：https://writings.sh/post/longest-increasing-subsequence-revisited
    int lengthOfLIS(vector<int> &nums){
        vector<int> dp;
        for (int &num : nums){
            if (dp.empty() || num > dp.back())
                dp.push_back(num);
            else{
                auto it = lower_bound(dp.begin(), dp.end(), num);
                *it = num;
            }
        }
        return dp.size();
    }
};
// @lc code=end
