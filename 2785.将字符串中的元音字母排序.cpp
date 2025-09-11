// For VSCode Coding
#include <bits/stdc++.h>
using namespace std;
//

/*
 * @lc app=leetcode.cn id=2785 lang=cpp
 *
 * [2785] 将字符串中的元音字母排序
 */

// @lc code=start
class Solution {


public:
    string sortVowels(string s) {
        vector<int> index;
        vector<char> x;
        for (int i = 0; i < s.size(); i++) {
            char C = toupper(s[i]);
            if (C == 'A' || C == 'E' || C == 'I' || C == 'O' || C == 'U') {
                index.push_back(i);
                x.push_back(s[i]);
            }
        }
        sort(x.begin(), x.end());

        for (int i = 0; i < x.size(); i++) {
            s[index[i]] = x[i];
        }
        return s;
    }
};
// @lc code=end
