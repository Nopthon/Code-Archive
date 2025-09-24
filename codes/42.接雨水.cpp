// For VSCode Coding
#include <bits/stdc++.h>
using namespace std;
//

/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// 朴素解，逐层扫描
class Plain_Solution {
public:
    int trap(vector<int>& height) {
        // 从最底层开始，一层一层解决
        // 时间复杂度 O(Max * n)
        // Max 过大时会 TLE

        int ans = 0;
        int floor = 0;
        int Max = *max_element(height.begin(), height.end());
        // 容易得到 l, r 只会向内收缩，因此将双指针置于 for 循环之外，减少一点常数
        int l = 0, r = height.size()-1;

        while(floor <= Max){
            while(l <= r && height[l] - floor <= 0) l++;
            while(l <= r && height[r] - floor <= 0) r--;
            if (l > r) break;
            for(int i = l+1; i < r; i++){
                if(height[i] - floor <= 0) ans++;
            }

            floor++;
        }
        return ans;
    }
};

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        // 先假设最右侧有一个无限高的墙，从左到右进行水的填充
        // 再假设最左侧有一个无限高的墙，从右往左进行水的填充
        // 取这两次填充的交集∩，即可得到正确的水量
        // （我们知道一个“坑”的蓄水量被左边与右边的最高墙限制，前述假设分别解除了某一侧的限制）
        // 空间复杂度较大
        // 是官解的方法一，不过我没从动态规划上想，官解给的图非常直观
        vector<int> leftMax(height.size()), rightMax(height.size());
        for(int i = 0, leftptr = 0; i < height.size(); i++){
            leftMax[i] = max(leftptr - height[i], 0);
            leftptr = max(leftptr, height[i]);
        }

        for(int i = height.size()-1, rightptr = 0; i >= 0; i--){
            rightMax[i] = max(rightptr - height[i], 0);
            rightptr = max(rightptr, height[i]);
        }

        int ans = 0; 
        
        for(int i = 0; i < height.size(); i++){
            ans += min(leftMax[i], rightMax[i]);
        }
        return ans;
    }
};
// @lc code=end

