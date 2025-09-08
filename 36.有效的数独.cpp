// For VSCode Coding
#include <bits/stdc++.h>
using namespace std;
//

/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // row
        for (int i = 0; i < 9; i++)
        {
            vector<bool> note(10, false);
            for (int j = 0; j < 9; j++)
            {
                // check
                if (board[i][j] != '.')
                {
                    int num = board[i][j] - '0';
                    if (note[num]) return false;
                    note[num] = true;
                }
            }
        }
        
        // col
        for (int j = 0; j < 9; j++)
        {
            vector<bool> note(10, false);
            for (int i = 0; i < 9; i++)
            {   
                // same logic
                if (board[i][j] != '.')
                {
                    int num = board[i][j] - '0';
                    if (note[num]) return false;
                    note[num] = true;
                }
            }
        }
        
        // grid
        for (int box = 0; box < 9; box++)
        {
            vector<bool> note(10, false);
            int r = (box / 3) * 3, c = (box % 3) * 3;
            for (int i = r; i < r + 3; i++)
                for (int j = c; j < c + 3; j++)
                {
                    if (board[i][j] != '.')
                    {
                        int num = board[i][j] - '0';
                        if (note[num]) return false;
                        note[num] = true;
                    }
                }
        }
        
        return true;
    }
};
// @lc code=end

