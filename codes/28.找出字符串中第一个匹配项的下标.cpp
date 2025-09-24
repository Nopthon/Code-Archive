// For VSCode Coding
#include <bits/stdc++.h>
using namespace std;
//

/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

/*
 * 这里是使用了 find 函数的程序
 * class Solution {
 * public:
 *     int strStr(string haystack, string needle) {
 *         auto where = haystack.find(needle);
 *         if(where != string::npos){
 *             return where;
 *         }
 *         else return -1;
 *     }
 * };
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        // 这里是采用 KMP 查找算法的解答
        if (needle.empty()) return 0;
        int len1 = haystack.size();
        int len2 = needle.size();
        // 第一步：构造前缀函数
        vector<int> pi(len2, 0);
        for (int i = 1; i < len2; i++) {
            int j = pi[i - 1];
            while (j > 0 && needle[i] != needle[j]) j = pi[j - 1];
            if (needle[i] == needle[j]) j++;
            pi[i] = j;
        }
        // 第二步：一次遍历查找
        for (int i = 0, j = 0; i < len1; i++) {
            while (j > 0 && haystack[i] != needle[j]) j = pi[j - 1];
            if (haystack[i] == needle[j]) j++;
            if (j == len2) return i - len2 + 1;
        }
        return -1;
    }
};
// @lc code=end
