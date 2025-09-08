// For VSCode Coding
#include <bits/stdc++.h>
using namespace std;
//

/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start

/* 暴力解，O(n^2)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i<nums.size()-1; i++){
            for(int j = i+1; j<nums.size(); j++){
                if(nums[i] + nums[j] == target){
                    return {i,j};
                }
            }
        }
        return {};
    }
};
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 哈希表加速查找速率，O(n)
        unordered_map <int,int> hashmap;
        for(int i = 0; i < nums.size(); i++){
            if(hashmap.find(target-nums[i]) != hashmap.end()){
                return {i,hashmap[target-nums[i]]};
            }
            hashmap[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end

