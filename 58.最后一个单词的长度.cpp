// For VSCode Coding
#include <bits/stdc++.h>
using namespace std;
//

/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        // 从后往前找，跳过一开始的空格
        int ans = 0, i = s.size()-1;
        while(s[i] == ' ') i--;
        while(i >= 0 && s[i] != ' ') {
            i--; ans++;
        }
        return ans;
    }
};
// @lc code=end

