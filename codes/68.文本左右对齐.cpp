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
            // 准备填入的单词填不下，这种情况下 i 不会自增
            if (cur_len + words[i].length() + min(0, (int)cur_words.size() - 1) > maxWidth) {
                int space_cnt = maxWidth - cur_len;
                int dived = space_cnt / (cur_words.size() - 1);
                int rem = space_cnt % (cur_words.size() - 1);

                string thisline = cur_words.front();
                if (cur_words.size() == 1) {
                    thisline.append(space_cnt, ' ');
                    ans.push_back(thisline);
                } else {
                    for (int j = 1; j < cur_words.size(); j++) {
                        int ext = rem > 0 ? 1 : 0;
                        rem--;
                        thisline.append(dived + ext, ' ');
                        thisline.append(cur_words[j]);
                    }
                    ans.push_back(thisline);
                }
                // 清空 cur_words 与 长度数据
                cur_len = 0;
                cur_words.clear();
            }
            // 准备填入的单词能填下
            else {
                cur_len += words[i].length();
                cur_words.push_back(words[i]);
                i++;
            }
        }

        if (!cur_words.empty()) {
            string thisline = cur_words.front();
            if (cur_words.size() == 1) {
                ans.push_back(thisline);
            } else {
                for (int i = 1; i < cur_words.size(); i++) {
                    thisline.append(1, ' ');
                    thisline.append(cur_words[i]);
                }
                ans.push_back(thisline);
            }
        }
        return ans;
    }
};
// @lc code=end
