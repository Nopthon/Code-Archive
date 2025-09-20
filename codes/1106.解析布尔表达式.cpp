// For VSCode Coding
#include <bits/stdc++.h>
using namespace std;
//

/*
 * @lc app=leetcode.cn id=1106 lang=cpp
 *
 * [1106] 解析布尔表达式
 */

// @lc code=start
class Solution {
public:
    bool parseBoolExpr(string expression) {
        // 最关键的就是嵌套运算下的计算处理
        // 因为栈的 “后进先出” 与嵌套括号的逻辑处理类似
        // 因此我们可以将 expression 的元素依次入栈，每次遇到右括号时进行一次处理
        bool ans;
        stack <char> expr;
        for(char& c : expression){
            // 逗号和左括号直接跳过
            if(c == ',' || c == '(') continue;
            // 每次遇到右括号进行一次处理
            if(c == ')'){
                // 因为计算符比参数先入栈，所以需要一个临时数组存储参数的值
                vector<char> q;
                while(expr.top() == 't' || expr.top() == 'f'){
                    q.push_back(expr.top());
                    expr.pop();
                }
                char bitcalc = expr.top();
                expr.pop();

                switch (bitcalc){
                    case '!':
                        if(q[0] == 't'){
                            expr.push('f');
                        } else expr.push('t');
                        break;
                    case '|':
                        if(find(q.begin(), q.end(), 't') != q.end()){
                            expr.push('t');
                        } else expr.push('f');
                        break;
                    case '&':
                        if(find(q.begin(), q.end(), 'f') != q.end()){
                            expr.push('f');
                        } else expr.push('t');
                        break;
                }
            }
            // 否则原样入栈 
            else expr.push(c);
        }
        return expr.top() == 't' ? true : false;
    }
};
// @lc code=end

