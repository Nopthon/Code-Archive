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
        // 已知对任意 x，2*x都是偶数
        // 已知如果落单的数 x 为奇数，那么通过二分计算区间和就可以利用奇偶性找到落单的奇数
        // 二分区间时，区间和为奇数的区间说明这段区间有 x
        // 如果落单的数 x 为偶数，那就将所有数字加1，然后同上处理，最后答案 -1
        int len = nums.size();
        vector<int> presum(len);


    }
};
// @lc code=end

