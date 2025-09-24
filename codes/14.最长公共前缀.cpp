// For VSCode Coding
#include <bits/stdc++.h>
using namespace std;
//

/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs.size();
        string ans;
        for(int i = 0; strs[0][i] != '\0';i++){
            char x = strs[0][i];
            bool check = true;
            for(int j = 1; j < len; j++){
                if(strs[j][i]  != x){
                    check = false;
                    break;
                }
            }
            if(check){
                ans += x;
            }
            else {
                break;
            }
        }
        return ans;
    }
};
// @lc code=end

