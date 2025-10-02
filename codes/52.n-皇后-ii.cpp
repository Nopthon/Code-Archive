// For VSCode Coding
#include <bits/stdc++.h>
using namespace std;
//

/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N 皇后 II
 */

// 打表解，时间复杂度 O(1)
// 不建议使用
class Abnormal_Solution{
public:
    int ans[9]={1,0,0,2,10,4,40,92,352};
    int totalNQueens(int n) {
        return ans[n-1];
    }
};

// @lc code=start
class Solution {
private:
    void dfs(int row, int n, int& ans, vector<bool>& col, vector<bool>& diag1, vector<bool>& diag2) {
        if (row == n) {
            ans++;
            return;
        }

        for (int c = 0; c < n; c++) {
            // 跳过已经产生冲突的列
            if (col[c] || diag1[row - c + n - 1] || diag2[row + c]) continue;
            // 放置皇后并标记已经占位的列，对角线
            col[c] = diag1[row - c + n - 1] = diag2[row + c] = true;
            // 向下一行搜索
            dfs(row + 1, n, ans, col, diag1, diag2);
            // 回溯
            col[c] = diag1[row - c + n - 1] = diag2[row + c] = false;
        }
    }

public:
    int totalNQueens(int n) {
        // 参见 LeetCode 51
        int ans = 0;
        vector<bool> col(n, false), diag1(2 * n - 1, false), diag2(2 * n - 1, false);
        dfs(0, n, ans, col, diag1, diag2);
        return ans;
    }
};
// @lc code=end
