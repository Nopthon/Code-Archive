// For VSCode Coding
#include <bits/stdc++.h>
using namespace std;
//

/*
 * @lc app=leetcode.cn id=68 lang=cpp
 *
 * [68] 文本左右对齐
 */

// @lc code=start
class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        // 每次填入一个单词前判断是否会超出maxWidth
        // 如果超出，为当前单词序列添加空格，然后输出清空当前单词序列
        // 结束后对最后一行进行左对齐的特殊处理
        int n = words.size();
        int cur_len = 0;
        vector<string> cur_words, ans;
        for (int i = 0; i < words.size();) {
            // 加上当前单词后所需的总长度（新单词长+单词总长+当前空格数）是否大于 maxWidth
            if (cur_len + words[i].length() + cur_words.size() > maxWidth){
                // 可插入空格数
                int space_cnt = maxWidth - cur_len;
                int dived = 0;
                int rem = 0;
                if (cur_words.size() > 1) {
                    // 平均不少于 dived 个空格
                    dived = space_cnt / (cur_words.size() - 1);
                    // 前 rem 个空格插入点需要多一个空格
                    rem = space_cnt % (cur_words.size() - 1);
                }
                string thisline = cur_words.front();
                if (cur_words.size() == 1) {
                    thisline.append(space_cnt, ' ');
                    ans.push_back(thisline);
                } else {
                    for (int j = 1; j < cur_words.size(); j++) {
                        // 第一次提交时出现了 std::length_error
                        // 可能是 append 的 cnt 参数出现了负数
                        if (rem > 0) {
                            thisline.append(dived + 1, ' ');
                            rem--;
                        } else {
                            thisline.append(dived, ' ');
                        }
                        thisline.append(cur_words[j]);
                    }
                    ans.push_back(thisline);
                }
                cur_len = 0;
                cur_words.clear();
            } 
            
            else {
                cur_len += words[i].length();
                cur_words.push_back(words[i]);
                // 注意 i++ 在这里
                i++;
            }
        }

        // 处理最后一行
        if (!cur_words.empty()) {
            string thisline = cur_words.front();
            for (int i = 1; i < cur_words.size(); i++) {
                thisline.append(1, ' ');
                thisline.append(cur_words[i]);
            }
            // 在末尾填充空格
            thisline.append(maxWidth - thisline.size(), ' ');
            ans.push_back(thisline);
        }
        return ans;
    }
};
// @lc code=end
