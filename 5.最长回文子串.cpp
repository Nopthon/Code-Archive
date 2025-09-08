// For VSCode Coding
#include <bits/stdc++.h>
using namespace std;
//

/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

/* 最朴素的搜索 O(n^2)，并且常数也比较烂，概率 TLE 概率 AC
class Solution {
public:
    string longestPalindrome(string s) {
        string ans(1,s[0]);
        int len = s.size();
        for(int i = 0; i < len; i++){
            string tmp(1,s[i]);
            for(int j = 1; i >= j && i+j < len; j++){
                if (s[i-j] == s[i+j]) {
                    tmp = s[i-j] + tmp + s[i+j];
                } else break;
                if (tmp.size() > ans.size()) {
                    ans = tmp;
                }
            }
        }
        for(int i = 0; i < len-1; i++){
            string tmp;
            for(int j = 0; i >= j && i+j+1 < len; j++){
                if (s[i-j] == s[i+1+j]) {
                    tmp = s[i-j] + tmp + s[i+j+1];
                } else break;
                if (tmp.size() > ans.size()) {
                    ans = tmp;
                }
            }
        }
        return ans;
    }
};
*/



// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        // Manacher 算法（对应的Luogu P3805模板题都标蓝了，wow）
        // Step 1. 预处理，统一成奇数长度字符串（原字符串保留）
        string str = "#";
        for(char ch : s){
            str += string(1,ch) + "#";
        }
        // Step 2. 

    }
};
// @lc code=end

