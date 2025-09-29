// For VSCode Coding
#include <bits/stdc++.h>
using namespace std;
//

/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        // 考虑一个可变长度的滑动窗口
        // 右边界向右扩展直到实现覆盖子串，之后收缩左边界直到字串长度出现极短值
        // 循环上述过程，直到右指针达到 s.end()
        // 关键是：如何快速判断子串是否覆盖
        // 我们维护两个计数数组，分别对窗口与 t 的字母进行桶计数
        // 时间复杂度 O(m + n)，m, n 分别表示两个字符串的长度
        int n = s.size();
        int l = 0, r = 0;                               // 滑动窗口左右边界 [a,b]
        int start = 0, min_len = INT_MAX;               // 最小字串的起始点与长度，便于 substr
        vector<int> t_count(128), window(128);          // 两个桶计数数组
        int diff = 0;                                   // diff 记录剩余需要匹配的不同字母个数
                                                        // diff == 0 时说明已实现覆盖
        for (char& c : t) t_count[c]++;
        for (int& x : t_count)
            if (x > 0) diff++;                          // diff 初始化

        while (r < n) {
            if (t_count[s[r]] != 0) {
                window[s[r]]++;
                if (window[s[r]] == t_count[s[r]]) {
                    diff--;                             // 多了一个覆盖的字母
                }
                while (diff == 0) {
                    if (window[s[l]] == t_count[s[l]] && t_count[s[l]] != 0) {
                        diff++;
                        int len = r-l+1;
                        if(len < min_len){
                            start = l;
                            min_len = len;
                        }
                    }
                    window[s[l]]--;
                    l++;
                }
            }
            r++;
        }

        return (min_len == INT_MAX ? "" : s.substr(start, min_len));
    }
};
// @lc code=end

// diff 的思想在很多题目中都会使用到，比如 LeetCode 438
// 仓库中 LeetCode 438 采用的是不使用 diff 变量的常数更大的做法