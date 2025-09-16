// For VSCode Coding
#include <bits/stdc++.h>
using namespace std;
//

/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // j 记录最左侧的 0
        for(int k = 1, j = 0; k < nums.size(); k++){
            while(j<k && nums[j] != 0) j++;
            if(j<k && nums[k] != 0){
                swap(nums[j], nums[k]);
            }
        }
    }
};
// @lc code=end

