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
private:
    bool check (vector<int>& t, vector<int>& w){
        for(int i = 0; i < 128; i++){
            if(t[i] > w[i]) return false;
        }
        return true;
    }

public:
    string minWindow(string s, string t) {
        // 考虑一个滑动窗口
        // 右边界向右扩展直到实现覆盖子串，之后收缩左边界直到字串长度出现极短值
        // 循环上述过程，直到右指针达到 s.end()
        // 关键是：如何快速判断子串是否覆盖
        // 我们维护两个计数数组，分别对窗口与 t 的字母进行计数
        // 
        int l = 0, r = 0;                           // 滑动窗口左右边界（[a,b]）
        int start = 0, len = INT_MAX;               // 最小字串的起始点与长度，便于 substr
        vector<int> t_count(128), window(128);      // 两个计数数组

        for(char &c : t) t_count[(int)c]++;
        while(r < s.size()){
            if(t_count[(int)s[r]]){
                window[(int)s[r]]++;
                if(check(t_count,window)){
                    while(l<=r){
                        l++;
                        if(t_count[(int)s[l]]){
                            window[(int)s[l]]--;
                            if(!check(t_count,window)) break;
                        }
                    }
                    if(r-l+2 < len){
                        start = l-1;
                        len = r-l+2;
                    }
                }
            }
            r++;
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};
// @lc code=end

