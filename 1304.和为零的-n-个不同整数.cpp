// For VSCode Coding
#include <bits/stdc++.h>
using namespace std;
//

/*
 * @lc app=leetcode.cn id=1304 lang=cpp
 *
 * [1304] 和为零的 N 个不同整数
 */

// @lc code=start
class Solution {
public:
    vector<int> sumZero(int n) {
        // 无脑构造 n-1 长度的单调递增数列，由最后一个数字“清零”
        // n <= 1k 
        int sum = 0;
        vector<int> ans;
        for(int i = 1; i < n; i++){
            ans.push_back(i);
            sum+=i;
        }
        ans.push_back(-1*sum);
        return ans;
    }
};
// @lc code=end

