// For VSCode Coding
#include <bits/stdc++.h>
using namespace std;
//

/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        // 针对于先出现右括号的样例，# 作为占位符
        st.push('#');
        for(int i = 0; i < s.length(); i++){
            switch(s[i]){
                case '(':
                case '{':
                case '[':
                    st.push(s[i]);
                    break;
                case ')':
                    if(st.top() == '(')
                        st.pop();
                    else return false;
                    break;
                case '}':
                    if(st.top() == '{')
                        st.pop();
                    else return false;
                    break;
                case ']':
                    if(st.top() == '[')
                        st.pop();
                    else return false;
                    break;
            }
        }
        if(st.top() == '#') return true;
        else return false;
    }
};
// @lc code=end

