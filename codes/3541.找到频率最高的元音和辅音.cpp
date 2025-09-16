// For VSCode Coding
#include <bits/stdc++.h>
using namespace std;
//

/*
 * @lc app=leetcode.cn id=3541 lang=cpp
 *
 * [3541] 找到频率最高的元音和辅音
 */

// @lc code=start
class Solution {
public:
    int maxFreqSum(string s) {
        // 桶存储每个字母的出现个数，两次取最大值
        vector<int> ab(26,0);
        for(char &c : s) 
            ab[(int)(c-'a')]++;
        int ans = max({ab[0], ab[4], ab[8], ab[14], ab[20]});
        ab[0] = ab[4] = ab[8] = ab[14] = ab[20] = 0;
        return ans + *max_element(ab.begin(), ab.end());
    }
};
// @lc code=end

