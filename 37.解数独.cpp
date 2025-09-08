// For VSCode Coding
#include <bits/stdc++.h>
using namespace std;
//

/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
class Solution
{
private:
    // From T36
    bool isValid(vector<vector<char>> &board, int x, int y, char num) {
        int n = num - '0';
        // row check
        for (int j = 0; j < 9; j++) {
            if (board[x][j] == num) return false;
        }
        // col check
        for (int i = 0; i < 9; i++) {
            if (board[i][y] == num) return false;
        }
        // box check
        int boxRow = (x / 3) * 3;
        int boxCol = (y / 3) * 3;
        for (int i = boxRow; i < boxRow + 3; i++) {
            for (int j = boxCol; j < boxCol + 3; j++) {
                if (board[i][j] == num) return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>> &board, int x, int y)
    {
        // precheck
        if (x == board.size()) return true;            // over
        if (y == board[0].size()) return solve(board, x + 1, 0);    // next row
        if (board[x][y] != '.') return solve(board, x, y + 1);      // NaN
        // aN
        for (char i = '1'; i <= '9'; i++) {
            // 检查逻辑和 T36 不一样
            if (isValid(board, x, y,i))
                board[x][y] = i;
            else continue;
            if (solve(board, x, y + 1))
                return true;
            // reverse
            board[x][y] = '.';
        }
        // go back
        return false;
    }

public:
    void solveSudoku(vector<vector<char>> &board)
    {
        // 试错，回溯，直到找到正解
        solve(board,0,0);
        return;
    }
};
// @lc code=end
