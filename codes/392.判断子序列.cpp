// For VSCode Coding
#include <bits/stdc++.h>
using namespace std;
//

/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

//
class Original_Solution {
public:
    bool isSubsequence(string s, string t) {
        // 对原始题目来说只有一个 s 和一个 t 
        // 直接使用两个指针扫描一遍即可
        if (s.empty()) return true;
        int sp = 0, tp = 0;
        int sn = s.length(), tn = t.length();
        for ( ;tp < tn; tp++){
            if(s[sp] == t[tp]){
                sp++;
            }
            // s 被逐字符匹配，为子序列
            if (sp == sn) {
                return true; 
            }
        }
        // t 被完全扫描，s 依旧有不匹配部分
        return false;
    }
};


// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        // 对于进阶问题（大量的 s 与一个 t），考虑对原数据进行预处理
        // 原来的双指针方案一直在做 “寻找下一个匹配字符” 的事情
        // 我们不妨设计预设计一个二维数组 a[m][n] 
        // a[m][n] 表示 t 字符串 “从 m 位置开始第一次出现 n 字母的位置”
        // 经过这样的一轮预处理后，接下来的匹配都将是 O(sn) 时间复杂度
        int sn = s.length(), tn = t.length();
        vector<vector<int>> a(tn+1, vector<int> (26, 0));
        // 我们默认从字符串末端出发，第一次出现任意字母的位置为 -1，即不存在
        for (int j = 0; j < 26; j++) {
            a[tn][j] = -1;
        }
        // 逆向遍历，确保最后更新的位置一定是最靠左的位置
        for (int i = tn - 1; i >= 0; i--) {
            a[i] = a[i + 1];        // 对于不改变索引的其他 25 个字母直接继承后一个索引位置的结果
            a[i][t[i] - 'a'] = i;
        }

        // 取 index = -1 是为了确保第一个字母能够正常被搜索
        // 不然 index = 0 的情况下 t 的第一个字母会被忽视
        int index = -1;
        for (char &c : s) {
            // 尝试寻找下一个正确的索引
            index = a[index+1][c - 'a'];
            // 发现有一个向后无法找到的字母
            if (index == -1) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

