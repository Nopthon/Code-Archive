// For VSCode Coding
#include <bits/stdc++.h>
using namespace std;
//

/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
class Plain_Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // 题干已经提示了使用前/后缀积数组进行解答
        // 不考虑空间复杂度
        int n = nums.size();
        vector<int> prefix(n), suffix(n), answer(n);
        for(int Mul = 1, i = 0; i < n; i++){
            Mul *= nums[i];
            prefix[i] = Mul;
        }
        for(int Mul = 1, i = n-1; i >= 0; i--){
            Mul *= nums[i];
            suffix[i] = Mul;
        }
        for(int Ans = 1, i = 0; i < n; i++, Ans = 1){
            if(i > 0) Ans *= prefix[i-1];
            if(i < n-1) Ans *= suffix[i+1];
            answer[i] = Ans;
        }
        return answer;
    }
};

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // 不难发现前/后缀积的每个元素只会用到一次
        // 所以将前/后缀积数组转化为单独的 left right 变量
        // 动态计算
        int n = nums.size();
        vector<int> answer(n,1);
        for(int left = 1, i = 0; i < n-1; i++){
            left *= nums[i];
            answer[i+1] *= left;
        }
        for(int right = 1, i = n-1; i > 0; i--){
            right *= nums[i];
            answer[i-1] *= right;
        }
        return answer;
    }
};
// @lc code=end

