// For VSCode Coding
#include <bits/stdc++.h>
using namespace std;
//

/*
 * @lc app=leetcode.cn id=1935 lang=cpp
 *
 * [1935] 可以输入的最大单词数
 */

// @lc code=start
class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        // bool 数组记录缺失字母
        // skip 记录当前单词是否已经缺少字母
        // 空格可以重置 skip 为 false，表示扫描到新的单词
        // (!skip && 遇到空格) 表示一个单词可以被完整输入
        bool broken[26] = {0};
        for(char &c : brokenLetters){
            broken[c-'a'] = true;
        }
        
        text += " ";                    // 确保最后一个单词可以被判定
        int ans = 0;
        bool skip = false;
        for(int i = 0; i < text.length(); i++){
            if(!skip){
                if(text[i] == ' '){
                    ans++;
                    continue;
                }
                if(broken[text[i]-'a']){
                    skip = true;
                }
            }
            if(text[i] == ' '){
                skip = false;
            }
        }
        return ans;
    }
};
// @lc code=end

