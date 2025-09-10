// For VSCode Coding
#include <bits/stdc++.h>
using namespace std;
//

/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 异或运算的特性：
        // a ^ a ^ b = b    （与计算顺序无关）
        // 将所有数字进行异或，计算结果就是落单的数字
        int result = 0;
        for (int num : nums) result ^= num;
        return result;
    }
};
// @lc code=end
