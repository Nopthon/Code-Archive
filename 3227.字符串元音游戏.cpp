// For VSCode Coding
#include <bits/stdc++.h>
using namespace std;
//

/*
 * @lc app=leetcode.cn id=3227 lang=cpp
 *
 * [3227] 字符串元音游戏
 */

// @lc code=start
class Solution {
public:
    bool doesAliceWin(string s) {
        // 博弈论小游戏
        // 如果没有元音字母，Alice loses
        // 如果有奇数个元音字母，Alice 一次移除整个字符串，Alice wins
        // 如果有正偶数个元音字母，Alice 一次移除到只剩下一个元音字母
        // 此时 Bob 无法操作或只能拿辅音字母，Alice 移除剩下的字符串，Alice wins
        // 实践到代码中就是，只要查询到元音字母就 return true，否则 return false
        for(char &x : s) if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') return true; return false;
    }
};
// @lc code=end

