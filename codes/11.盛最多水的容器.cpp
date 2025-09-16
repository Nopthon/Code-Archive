// For VSCode Coding
#include <bits/stdc++.h>
using namespace std;
//

/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int ans = (r-l)*min(height[l],height[r]);
        while(l<r){
            if(height[l] < height[r]){
                l++;
                if(height[l] > height[l-1]){
                    ans = max((r-l)*min(height[l],height[r]),ans);
                }
            }
            else {
                r--;
                if(height[r] > height[r+1]){
                    ans = max((r-l)*min(height[l],height[r]),ans);
                }
            }
        }

        return ans;
    }
};
// @lc code=end

