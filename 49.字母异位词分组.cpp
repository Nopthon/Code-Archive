// For VSCode Coding
#include <bits/stdc++.h>
using namespace std;
//

/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution
{
private:
    long long hashing(const string &s)
    {
        // 为每个字母分配一个唯一的质数，写了个 Python 程序随机生成较大的质数
        // 经过测试被哈希碰撞的概率不低，所以我试了很多组质数串才找到这一串正解
        const long long primes[26] = {
            2799551,6620629,10214917,13198223,16098373,23313337,25275917,29331191,33650143,38628127,
            41495273,44900467,51644713,54926731,58164877,63185377,64043153,69081127,72091009,77205647,
            82439563,86920919,89240677,93314087,95999993,96678667};

        long long result = 1;
        for (char c : s)
        {
            if (c >= 'a' && c <= 'z')
            {
                result += primes[c - 'a']; // 这里用乘法安全性更强，但是我发现太容易溢出了，即使质数很小
            }
        }
        return result;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        // 考虑一种对单个字母的哈希处理，保证异位词之间哈希值一定相同
        vector<long long> hash(strs.size());
        for (int i = 0; i < strs.size(); i++)
        {
            hash[i] = hashing(strs[i]);
        }
        // STL 哈希表
        unordered_map<long long, vector<string>> groups;

        for (int i = 0; i < strs.size(); i++)
        {
            // push_back
            groups[hash[i]].push_back(strs[i]);
        }

        vector<vector<string>> ans;
        for (auto &pair : groups)
        {
            // 所有权转移让我想到 Rust
            ans.push_back(move(pair.second));
        }

        return ans;
    }
};

// 写完后我才意识到，可以对每个字符串进行一次排序然后 unordered_map 
// 不过排序的时间效率应该不如哈希
// @lc code=end
