// For VSCode Coding
#include <bits/stdc++.h>
using namespace std;
//

/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // 要求 O(log n) 算法，考虑二分查找
        int left = 0, right = nums.size()-1, ans = -1;
        while(left<=right){
            int mid = left + (right - left) / 2;
            // 这里说明找到了完全匹配的位置
            if(nums[mid] == target){
                ans = mid; break;
            }
            else if(nums[mid] < target){
                left = mid + 1;
            }
            else right = mid - 1;
        }

        if(ans == -1){
            // 这里说明没找到匹配位置，以 left 作为插入位置返回
            return left;
        }
        else return ans;
    }
};
// @lc code=end

