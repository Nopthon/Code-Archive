// For VSCode Coding
#include <bits/stdc++.h>
using namespace std;
//

/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        int len = s.length();
        for(int i = 0; i < len; i++){
            switch (s[i]){
                case 'I':
                    if(i != len-1 && (s[i+1] == 'V' || s[i+1] == 'X')){
                        ans += s[i+1] == 'V' ? 4 : 9;
                        i++;
                    }
                    else ans += 1;
                    break;
                case 'X':
                    if(i != len-1 && (s[i+1] == 'L' || s[i+1] == 'C')){
                        ans += s[i+1] == 'L' ? 40 : 90;
                        i++;
                    }
                    else ans += 10;
                    break;
                case 'C':
                    if(i != len-1 && (s[i+1] == 'D' || s[i+1] == 'M')){
                        ans += s[i+1] == 'D' ? 400 : 900;
                        i++;
                    }
                    else ans += 100;
                    break;
                case 'V':
                    ans += 5;
                    break;
                case 'L':
                    ans += 50;
                    break;
                case 'D':
                    ans += 500;
                    break;
                case 'M':
                    ans += 1000;
                    break;
            }
        }
        return ans;
    }
};
// @lc code=end

