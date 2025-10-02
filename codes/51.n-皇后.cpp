// For VSCode Coding
#include <bits/stdc++.h>
using namespace std;
//

/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
private:
    void dfs(int row, int n, vector<string>& Map, vector<vector<string>>& ans, vector<bool>& col, vector<bool>& diag1, vector<bool>& diag2) {
        if (row == n) {
            ans.push_back(Map);
            return;
        }
        
        for (int c = 0; c < n; c++) {
            // 跳过已经产生冲突的列
            if (col[c] || diag1[row - c + n - 1] || diag2[row + c]) continue;
            // 放置皇后并标记已经占位的列，对角线
            Map[row][c] = 'Q';
            col[c] = diag1[row - c + n - 1] = diag2[row + c] = true;
            // 向下一行搜索
            dfs(row + 1, n, Map, ans, col, diag1, diag2);
            // 回溯
            Map[row][c] = '.';
            col[c] = diag1[row - c + n - 1] = diag2[row + c] = false;
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        // 很纯粹的回溯法（DFS+剪枝）
        // 一行一行地放置棋子
        // 用三个数组分别记录列，主副对角线上的占用情况
        // 时间复杂度 O(n!)
        vector<string> Map(n, string(n,'.'));
        vector<vector<string>> ans;
        vector<bool> col(n,false), diag1(2*n-1,false), diag2(2*n-1,false);
        dfs(0, n, Map, ans, col, diag1, diag2);
        return ans;
    }
};
// @lc code=end

