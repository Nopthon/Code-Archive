// For VSCode Coding
#include <bits/stdc++.h>
using namespace std;
//

/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
// 不使用字符串操作
class Solution {
public:
    bool isPalindrome(int x) {
        // 特判
        if(x==0) return true;
        if(x<0 || x%10<=0) return false;
        // 对右半部分反转
        else {
            int rev = 0;
            while (x>rev){
                rev = 10 * rev + x%10; x/=10;
            }
            // 比较右半部分反转后是否与左半部分相等，下式分别考虑了偶数位数与奇数位数
            return x == rev || x == rev / 10;
        }
    }
};
// @lc code=end

