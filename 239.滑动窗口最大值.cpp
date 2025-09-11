// For VSCode Coding
#include <bits/stdc++.h>
using namespace std;
//

/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 创建一个存储索引值的单调递减队列
        // 对于每个索引 i，根据 nums[i] 的值进行单调递减的维护
        // 同时每次滑动窗口时，持续踢掉超出窗口的队首元素
        // 队首索引 p 对应的 nums[p] 始终是滑动窗口当前最大值
        vector<int> ans;
        deque<int> q;
        for(int i = 0; i < nums.size(); i++){
            while(!q.empty() && nums[q.back()] < nums[i]){
                q.pop_back();
            }
            q.push_back(i);
            if(i >= k-1){
                while(!q.empty() && q.front() <= i-k){
                    q.pop_front();
                }
                ans.push_back(nums[q.front()]);
            }
        }
        return ans;
    }
};
// @lc code=end

