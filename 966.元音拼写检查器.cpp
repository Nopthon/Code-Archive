// For VSCode Coding
#include <bits/stdc++.h>
using namespace std;
//

/*
 * @lc app=leetcode.cn id=966 lang=cpp
 *
 * [966] 元音拼写检查器
 */

// @lc code=start
class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        // 涉及到大量查找工作，对 wordlist 进行哈希表预处理
        // 空间换时间
        // 完全匹配 -> 大小写不匹配 -> 元音字母不匹配 -> 完全不匹配
        unordered_set<string> Perfect;
        unordered_map<string,string> Good;
        unordered_map<string,string> Bad;
        // pre 处理
        for(string& word : wordlist){
            Perfect.insert(word);

            string to_lower = {};
            for (char &c : word) {
                to_lower += (char)tolower(c);
            }
            if(!Good.count(to_lower)){
                Good.insert({to_lower, word});
            }

            string ign_vowel = {};
            for(char &c : to_lower){             // 注意这里是 to_lower
                if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
                    ign_vowel += '.';
                }
                else ign_vowel += c;
            }
            if(!Bad.count(ign_vowel)){
                Bad.insert({ign_vowel, word});
            }
        }
        // queries 判断
        for(string &word : queries){
            if(Perfect.count(word)){
                continue;
            }

            string to_lower = {};
            for (char &c : word) {
                to_lower += (char)tolower(c);
            }
            auto it = Good.find(to_lower);
            if (it != Good.end()) {
                word = it->second;
                continue;
            }

            string ign_vowel = {};
            for(char &c : to_lower){
                if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
                    ign_vowel += '.';
                }
                else ign_vowel += c;
            }
            it = Bad.find(ign_vowel);
            if (it != Bad.end()) {
                word = it->second;
                continue;
            }

            word = "";
        }
        return queries;
    }
};
// @lc code=end

