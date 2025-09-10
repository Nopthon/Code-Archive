// For VSCode Coding
#include <bits/stdc++.h>
using namespace std;
//

/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

/* 一开始的思路：维护一个可能的最长括号字串队列
class Solution {
public:
    int longestValidParentheses(string s) {
        // 最长括号字串队列
        queue<char> q;
        // 记录左右括号数量方便check合法性
        int l = 0, r = 0, ans = 0;
        for(int i = 0 ; i < s.size(); i++){
            // 压入队列
            q.push(s[i]);
            // 记录括号
            if(s[i] == '(') l++;
            else r++;
            // case: 恰好是一个完整子串
            if(l == r){
                ans = max(ans,(int)q.size());
                continue;
            }
            // case: 右括号多了，这个右括号及其前面的所有元素都需要被丢弃
            if(l < r){
                queue<char> empty;
                swap(empty, q);
                l = 0; r = 0;
                continue;
            }
            else continue;
        }
        // 注意到在遍历完所有括号时，当前队列的右端可能存在合法字串（左端肯定没有了）
        // 因此需要遍历两次，第二次从右往左进行遍历，两次答案取大可以保证正解
        // 时间复杂度约 O(2n)，常数较差，只能击败个位数 % 的程序
        return ans;
    }
};
*/

// @lc code=start
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        // 考虑到括号是“搭配出现的”，可以考虑使用栈进行 “消消乐”
        stack<int> st; st.push(-1); // 这个值不能动，它表示最左端子串（若存在）的长度起始点
        int ans = 0;

        for (int i = 0; i < s.size(); i++)
        {
            // 与其在队列操作中持续读取队列长度作为合格子串，不如让栈自身存储合法子串的起始索引
            // 现在栈每个元素都表示 “可以从这里为起点尝试构造子串”
            if (s[i] == '(') st.push(i);
            else
            {
                // “消消乐”
                st.pop();
                if (st.empty()) st.push(i); // 新的起点
                // 现在存入的括号和栈顶序号所对应的括号之间有一个字串
                else ans = max(ans, i - st.top());
            }
        }
        // 由于只需要一次遍历，常数得到优化
        // 有概率可以 runtime beats 100 % of cpp submissions 了
        return ans;
    }
};
// @lc code=end
