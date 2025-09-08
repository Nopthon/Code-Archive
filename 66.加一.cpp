// For VSCode Coding
#include <bits/stdc++.h>
using namespace std;
//

/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        digits.back()++;
        for(int i = digits.size()-1; i > 0; i--){
            if(digits[i] == 10){
                digits[i] = 0;
                digits[i-1]++;
            }
            else break;
        }
        if(digits.front() == 10){
            digits.front() = 0;
            /* insert 头插入 比 resize 尾添加 所需内存更多
            digits.insert(digits.begin(),1);
            */
            digits.resize(digits.size()+1);
            for(int i = digits.size()-2; i >= 0; i--){
                digits[i+1] = digits[i];
            }
            digits[0] = 1;

            return digits;
        }
        else return digits;
    }
};
// @lc code=end

