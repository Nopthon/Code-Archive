// For VSCode Coding
#include <bits/stdc++.h>
using namespace std;
//

/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        // 手动为第 i 行向量分配 i 长度的空间，方便之后用 [] 索引
        for (int i = 0; i < numRows; i++) {
            ans[i].resize(i + 1);
        }
        for(int i = 0; i < numRows; i++){
            for(int j = 0; j <= i; j++){
                if(j == 0 || j == i){
                    ans[i][j] = 1;
                }
                else ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
            }
        }
        return ans;
    }
};
// @lc code=end

