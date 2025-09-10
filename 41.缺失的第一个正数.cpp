// For VSCode Coding
#include <bits/stdc++.h>
using namespace std;
//

/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

/* 把下面的两轮单次遍历操作重复三次可以AC掉所有数据
// 通过增大双向遍历次数强制通过所有评测点也是重量级
for(int i = 0; i <= n; i++){
    if(nums[i] >= 1 && nums[i] <= n)
        swap(nums[nums[i]], nums[i]);

for(int i = n-1; i >= n; i++){
    if(nums[i] >= 1 && nums[i] <= n)
        swap(nums[nums[i]], nums[i]);
*/

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // 我们记 n = nums.size()
        // 一个长 n 的 nums 数组，没有出现的最小正整数一定在 [1, n+1]
        // 首先让处于 [1,n+1] 的 nums[i] 全部交换到 nums[nums[i]]
        // 然后一次遍历找第一处错位点 （nums[i] != i），或者无错位点，ans = n+1
        int n = nums.size();
        nums.push_back(-1);                     // 使 nums[n] 存在

        for (int i = 0; i <= n; i++) {
            // 这里为持续交换，直到当前元素不在 [1, n] 范围内或者已经处于正确位置
            // 交换后的 i 处的新元素继续参与交换，不会漏掉一些在某次交换以后被移到左侧的较大数字
            // 因为每一次交换至少可以实现一组 nums[i] == i ，因此时间复杂度保证为 O(n)
            while (nums[i] >= 1 && nums[i] <= n && nums[i] != nums[nums[i]]) {
                swap(nums[nums[i]], nums[i]);
            }
        }
        
        for(int i = 1; i <= n; i++){
            if(nums[i] != i) return i;
        }
        return n+1;
    }
};
// @lc code=end

