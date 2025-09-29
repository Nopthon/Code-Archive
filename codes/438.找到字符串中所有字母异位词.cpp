// For VSCode Coding
#include <bits/stdc++.h>
using namespace std;
//

/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start

// 更优的解答请参考 LeetCode 76 的 diff 变量优化
// 具有更优的常数优化
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // 找到异位词有以下方案：
        // 1. 基于频率的（比如质数乘积）哈希    2. 子串排序后比较相等
        // 3. 桶数组存储
        // 这里采用方案 3 ，构造一个“滑动窗口”动态处理桶数组值的变化

        if(s.size() < p.size()) return {};

        vector<int> ans;
        vector<int> barrel(26,0);
        vector<int> matched(26,0);
        for(char &c : p){
            matched[c - 'a']++;
        }
        // 初始化窗口
        for(int i = 0; i < p.size(); i++){
            barrel[s[i] - 'a']++;
        }
        if(memcmp(barrel.data(), matched.data(), 26 * sizeof(int)) == 0){
            ans.push_back(0);
        }
        // 滑动窗口
        for(int i = p.size(); i < s.size(); i++){
            barrel[s[i-p.size()] - 'a']--;
            barrel[s[i] - 'a']++;
            // 改用内存比较可加快速率
            if(memcmp(barrel.data(), matched.data(), 26 * sizeof(int)) == 0){
                ans.push_back(i-p.size()+1);
            }
        }
        return ans;
    }
};
// @lc code=end

