// For VSCode Coding
#include <bits/stdc++.h>
using namespace std;
//

/*
 * @lc app=leetcode.cn id=1317 lang=cpp
 *
 * [1317] 将整数转换为两个无零整数的和
 */

// @lc code=start
class Solution{
private:
    bool checkzero(int n) {
        while (n >= 10) {
            if (n % 10 == 0)
                return false;
            n /= 10;
        }
        return true;
    }

public:
    vector<int> getNoZeroIntegers(int n) {
        // 暴力搜，考虑到解非常多，随机数的平均用时可能比纯遍历更快
        for (int i = 1; i <= n; i++) {
            if (checkzero(i) && checkzero(n - i))
                return {i, n - i};
        }
        return {};
    }
};
// @lc code=end
