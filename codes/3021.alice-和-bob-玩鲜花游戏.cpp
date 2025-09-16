/*
 * @lc app=leetcode.cn id=3021 lang=cpp
 *
 * [3021] Alice 和 Bob 玩鲜花游戏
 */

// @lc code=start
class Solution {
public:
    long long flowerGame(int n, int m) {
    // 也就是找出所有的 (x,y)，满足：x+y>1, (x+y) is odd, 1<=x<=n 1<=y<=m
    // (x+y) is odd 可以理解为奇偶性不同
    long long n_odd = (n+1)>>1, n_even = (n)>>1, m_odd = (m+1)>>1, m_even = (m)>>1;
    return n_odd * m_even + n_even * m_odd;
    }
};
// @lc code=end

