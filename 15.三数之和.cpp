// For VSCode Coding
#include <bits/stdc++.h>
using namespace std;
//

/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int len = nums.size();
        // 避免纯暴力，采用“固定一个，找另外两个”的寻找方案
        // 使用双指针对“另外两个数”进行收束式寻找，单次寻找过程的时间复杂度缩小至
        // O(n) 总时间复杂度为 O(n^2)
        if (nums[len - 1] < 0) return {};

        for (int i = 0; i < len - 2; i++) {
            if (nums[i] > 0) break;
            for (int l = i + 1, r = len - 1; l < r;) {
                int sum = nums[l] + nums[r] + nums[i];
                if (sum == 0) {
                    // 如果每次都通过find判断重复元素会TLE
                    // if (find(ans.begin(), ans.end(), vector<int>{nums[i],
                    // nums[l], nums[r]}) == ans.end())
                    ans.push_back({nums[i], nums[l], nums[r]});
                    // 跳过重复元素，注意这两行代码插入的位置
                    while (l < r && nums[l] == nums[l + 1]) l++;
                    while (l < r && nums[r] == nums[r - 1]) r--;
                    l++;
                    r--;
                }
                else if (sum < 0) l++;
                else if (sum > 0) r--;
            }
            // 不出现重复解，所以跳过重复数字
            // 必须放在后面，否则会漏掉 nums[i] == nums[l] 的解
            // 放在前面的可以写 if (i > 0 && nums[i] == nums[i - 1]) continue;
            while (i < len - 1 && nums[i] == nums[i + 1]) i++;
        }
        // 也可以用一种很难想象的方式进行去重，直接用 set 定义答案数组最终再转化
        // set<vector<int>> ans;
        // return vector<vector<int>>(ans.begin(), ans.end());
        return ans;
    }
};

// @lc code=end
