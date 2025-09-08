// For VSCode Coding
#include <bits/stdc++.h>
using namespace std;
//

/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int len = nums.size(), curmax = 1, ans = 1;
        if (len < 1) return 0;
        // 数据点太水了导致的，runtime 甚至能 beats 99%+
        // 我应该使用hash方法吗
        sort(nums.begin(), nums.end());
        for (int i = 1; i < len; i++)
        {
            if (nums[i] == nums[i - 1] + 1)
            {
                curmax++;
                ans = max(ans, curmax);
            }
            else if (nums[i] != nums[i - 1]) curmax = 1;
        }
        return ans;
    }
};
// @lc code=end
