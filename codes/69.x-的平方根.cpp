// For VSCode Coding
#include <bits/stdc++.h>
using namespace std;
//

/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        // 二分方案
        // 这里的特判是为了避免 x / mid 中 mid = 0 的情况
        if(x <= 1) return x;
        int left = 0, right = min(x/2+1,46341); // 预计算了 sqrt{INT_MAX}
        while (left <= right){
            int mid = left + ((right - left) >> 1);
            if(mid < x / mid){
                left = mid + 1;
            }
            else if(mid > x / mid){
                right = mid - 1;
            }
            else return mid;
        }
        return right;
    }
};
// @lc code=end

