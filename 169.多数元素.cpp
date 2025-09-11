// For VSCode Coding
#include <bits/stdc++.h>
using namespace std;
//

/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // 设置一个 “擂台”，设置 “最多数” 与 “个数” 两个变量
        // 每一个等于 mostNum 的数字都使 cnt++
        // 每一个不等于 mostNum 的数字都可以抵消掉 cnt 的值（cnt--）
        // 当 cnt 的值为 0 时，这个数字成为新的 mostNum，并将 cnt 设为 1
        // 因为 “多数元素” 比其他所有的数字个数都要多
        // 所以一轮遍历以后处于 mostNum 的数字一定是 “多数元素”
        int mostNum = 1e9 + 1;                  // 确保不在 nums 数据范围内
        int cnt = 1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == mostNum) cnt++;
            else {
                cnt--;
                if(cnt == 0){
                    mostNum = nums[i];
                    cnt++;
                }
            }
        }
        return mostNum;
    } 
};
// @lc code=end

// 原来这个叫 Boyer-Moore 投票算法（实现有小区别）

