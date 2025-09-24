// For VSCode Coding
#include <bits/stdc++.h>
using namespace std;
//

/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 卡 O(log (m+n)) 复杂度，merge 复杂度 O(m+n) 不可取，考虑二分查找
        // 把 A[m] 和 B[n] 分成 A[0,...,i-1] + A[i,...,m] B[0,...,j-1] + B[j,...,m]
        // 把 A[0,...,i-1] B[0,...,j-1] 记作 left；A[i,...,m] B[j,...,m] 记作 right
        // 对于偶数情况，如果 left.len == right.len 且 left.max <= right.min
        // 说明 (left.max + right.min) // 2 为 平均值
        // 奇数情况同理。根据整除性质，用 (m+n+1) // 2 的方式统一运算

        if(nums1.size() > nums2.size()){
            nums1.swap(nums2);  // 保证 nums1 是较短的那个，考虑到二分查找 O(log (max (m,n)))
        }
        int len1 = nums1.size(), len2 = nums2.size();
        // 开始二分
        int left = 0, right = len1;
        while(left <= right){
            int i = (left + right) >> 1;
            int j = ((len1 + len2 + 1) >> 1) - i;
            // 以上确保了 left.len == right.len 或只差 1
            
            // 考虑边界情况（以及潜在的数组越界）
            int left1 = (i == 0) ? INT_MIN : nums1[i-1], right1 = (i == len1) ? INT_MAX : nums1[i];
            int left2 = (j == 0) ? INT_MIN : nums2[j-1], right2 = (j == len2) ? INT_MAX : nums2[j];

            if(left1 > right2){
                right = i - 1;
                continue;
            }
            else if(left2 > right1){
                left = i + 1;
                continue;
            }
            else{
                return (len1+len2)%2 ? (double)(max(left1,left2)) : \
                (double)((max(left1,left2) + min(right1, right2)) / 2.0);
            }

        }
        return 1.14;

    }
};
// @lc code=end

