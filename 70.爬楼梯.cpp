// For VSCode Coding
#include <bits/stdc++.h>
using namespace std;
//

/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        vector<int> fib(46,1);
        for(int i = 2; i <= n; i++){
            fib[i] = fib[i-1] + fib[i-2];
        }
        return fib[n];
    }
};
// @lc code=end

