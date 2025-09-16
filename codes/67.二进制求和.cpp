// For VSCode Coding
#include <bits/stdc++.h>
using namespace std;
//

/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size() > b.size()){
            int diff = a.size() - b.size();
                b = string(diff, '0') + b;
        }
        else if(a.size() < b.size()){
            int diff = b.size() - a.size();
                a = string(diff, '0') + a;
            }
        int len = a.size();
        bool carry = false;
        for(int i = len-1; i >= 0; --i){
            // char 转换为 int 计算
            int sum = (a[i] - '0') + (b[i] - '0') + carry;
            a[i] = (sum % 2) + '0';
            carry = sum > 1;
        }
        if(carry){
            a = "1" + a;
        }
        return a;
    }
};
// @lc code=end

