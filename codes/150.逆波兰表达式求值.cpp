// For VSCode Coding
#include <bits/stdc++.h>
using namespace std;
//

/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // 按顺序将数字入栈
        // 遇到符号就将栈顶两元素弹出求值，新的值入栈
        stack<int> st;
        for(string& token : tokens){
            if(token == "+"){
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                st.push(a+b);
            }
            else if(token == "-"){
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                st.push(a-b);
            }
            else if(token == "*"){
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                st.push(a*b);
            }
            else if(token == "/"){
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                st.push(a/b);
            }
            else{
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};
// @lc code=end

