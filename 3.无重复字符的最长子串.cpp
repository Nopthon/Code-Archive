// For VSCode Coding
#include <bits/stdc++.h>
susing namespace std;
//

/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;   // 双指针代替队列
        unordered_map<char, int> stored;    // char 最后一次在 int 处被发现
        int ans = 0;

        for(int right = 0; right < s.length(); right++){
            if(stored.find(s[right]) != stored.end()){
                // left 不需要一次移动一位，哈希表提供了一次性移位的信息
                left = max(left, stored[s[right]] + 1);
            }
            // Update
            stored[s[right]] = right;
            ans = max (ans, right - left + 1);
        }
        return ans;
    }
};
// @lc code=end

