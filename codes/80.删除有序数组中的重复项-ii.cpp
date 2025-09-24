// For VSCode Coding
#include <bits/stdc++.h>
using namespace std;
//

/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
 */

// 
class Plain_Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // 考虑两次遍历：
        // 第一次便利，将所有“多余”的元素设置为 "out" 值（不在数据范围的值）
        // 第二次遍历，根据out值进行向左填充，实现 “原地算法”
        int now = nums[0];
        int cnt = 1;
        const int OUT = 1e5;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == now){
                cnt++;
                if(cnt > 2){
                    nums[i] = OUT;
                }
            }
            else {
                cnt = 1;
                now = nums[i];
            }
        }
        int step = 0;
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] != OUT)
                nums[step++] = nums[i];
        return step;
    }
};


// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // 我们发现上面的第二次遍历中的 OUT 位置的值恰好是 nums[step - 2]
        // 可以利用快慢指针压缩到一次遍历，常数更优
        int len = nums.size();
        if(len <= 2) return len;
        int step = 2;
        for (int i = 2; i < len; i++)
            if (nums[i] != nums[step - 2])
                nums[step++] = nums[i];
        return step;
    }
};
// @lc code=end

