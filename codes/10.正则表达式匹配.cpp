// For VSCode Coding
#include <bits/stdc++.h>
using namespace std;
//

/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// 最开始我采用记忆化搜索来解决这个问题
// 记忆化搜索可以直观地理解正则匹配地过程，但是有递归的栈开销与较大的空间开销
// 记 m = s.length, n = p.length
// 时间复杂度 O(m * n)，空间复杂度 O(m * n) + O(m + n) = O(m * n)
class Another_Solution {
public:
    bool isMatch(string s, string p) {
        // 本题最难的地方在于：
        // 当对 s 匹配 .* 时，我们应该匹配到什么程度停下
        // 匹配过短/过长都会导致匹配错误
        // 我们不妨用记忆化搜索去分析
        // 下面给出的数组 vis 记忆化 s[i] 与 p[j] 是否匹配
        // -1 表示尚未 check；0 表示匹配Another_
        vector<vector<int>> vis(s.length() + 1, vector<int>(p.length() + 1, -1));

        // 因为正则表达式需要完全匹配，所以 check(s, p, 0, 0, vis) 的结果就是答案
        return check(s, p, 0, 0, vis);
    }

private:
    bool check(string& s, string& p, int i, int j, vector<vector<int>>& vis) {
        // 如果已经计算过这个状态，直接返回结果（这是优化的最关键一步）
        // 就像计算斐波那契数列一样，如果没有这一步会出现指数级的重复计算
        if (vis[i][j] != -1) return vis[i][j] == 1;

        // 当前层的判定结果
        bool res;

        if (j >= p.length()) res = (i == s.length()); // p 扫描完毕，判断 s 此时有没有扫描完
        
        else {
            // 检查当前字符是否匹配
            // 在 s 没有扫描完毕的基础上，判断 p[j] 是否为通配符 '.' 或者等于 s[i]  
            bool matched = (i < s.length() && (p[j] == '.' || p[j] == s[i]));

            // 如果下一个字符（存在且）是 '*'
            if (j + 1 < p.length() && p[j + 1] == '*') {
                // 要么直接跳过 *，对应 check(s, p, i, j + 2, vis)
                // 要么让 s 的下一个字母去匹配 *，对应 check(s, p, i, j + 2, vis)
                // 也就是每次向下一位搜索时都可以选择 “继续 * 的通配” 或 “停止 * 的通配” 
                // 注意 j 在结束 * 的通配前始终处于 * 前一位的位置，记录 * 前面的字母或通配符 '.'
                res = check(s, p, i, j + 2, vis) || (matched && check(s, p, i + 1, j, vis));
            }
            else {
                // 链式判断下一位是否也匹配
                res = matched && check(s, p, i + 1, j + 1, vis);
            }
        }

        // 存储计算结果
        vis[i][j] = res;
        return res;
    }
};


// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        // 对于记忆化搜索，我们有额外的栈调用（时间）开销与空间开销
        // 一方面，既然我们使用了 vis 这个二维数组存储了搜索状态
        // 不妨直接对这个二维数组进行动态规划，省去递归开销
        // 另一方面，我们发现对 vis[i][j] 的计算只依赖于 vis[i] 与 vis[i+1] 的内容
        // 因此我们可以利用滚动数组压缩空间使用
        // 记 m = s.length, n = p.length
        // 时间复杂度 O(m * n)，空间复杂度 O(n)
        int m = s.length(), n = p.length();
        vector<bool> dp1(n+1,false), dp2(n+1,false);

        // 先对 p 字符串末尾的 * 进行判断
        dp2[n] = true;
        for (int j = n - 1; j >= 0; j--)
            if (j + 1 < n && p[j + 1] == '*')
                dp2[j] = dp2[j + 2];


        // 在记忆化搜索进行递归时，vis[i][j] 是由索引值更大的 vis[][] 决定的
        // 因此如果不采用递归式写法，就需要从后往前遍历
        // 注意这里使用的最外层使用的是 s 遍历，因为最终判断是看 s 的
        // 不难发现循环中的内容可以和记忆化搜索解法的相关内容一一对应
        for (int i = m - 1; i >= 0; i--) {
            fill(dp1.begin(), dp1.end(), false);
            for (int j = n - 1; j >= 0; j--) {
                bool matched = (p[j] == s[i] || p[j] == '.');
                if (j + 1 < n && p[j + 1] == '*') {
                    dp1[j] = dp1[j+2] || (matched && dp2[j]); 
                } else {
                    dp1[j] = matched && dp2[j + 1];
                }
            }
            dp2 = dp1;
        }
        return dp2[0];
    }
};
// @lc code=end


// 其实我更欣赏记忆化搜索的方案，因为它真的很直观且满足时间复杂度