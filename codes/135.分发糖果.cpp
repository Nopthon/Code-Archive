// For VSCode Coding
#include <bits/stdc++.h>
using namespace std;
//

/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        // 5min 速写思路：（有后期修改）
        // 至少需要一人一个糖果
        int len = ratings.size();
        // 一个记录糖果数增加的数组
        vector<int> add(len);
        // 从左向右检查
        for(int i = 1; i < len; i++){
            if(ratings[i] > ratings[i-1]){
                add[i] = add[i-1] + 1;
            }
        }

        int ans = len + add[len-1];

        // 从右向左检查
        for(int i = len-2; i >= 0; --i){
            // 注意 && add[i] <= add[i+1] 是必要的
            // 或者 add[i] = max(add[i], add[i+1] + 1) 也可以
            if(ratings[i] > ratings[i+1] && add[i] <= add[i+1]){
                add[i] = add[i+1] + 1;
            }
            // 统计结果
            ans += add[i];
        }
        return ans;
    }
};
// @lc code=end

// Hard 题写得最快的一次

