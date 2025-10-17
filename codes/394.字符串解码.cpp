// For VSCode Coding
#include <bits/stdc++.h>
using namespace std;
//

/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

class During_the_Class_Solution {
public:
    string decodeString(string s) {
        // 课上写 Online Judge 的代码
        // 除了 string 不允许使用其他 STL 容器
        char Stack[100000];
        int numStack[100000];
        int ptr = -1;
        int numptr = -1;
        int n = s.size();
        for (int i = 0; i < n;) {
            if (s[i] == '[' || (s[i] >= 'a' && s[i] <= 'z')) {
                Stack[++ptr] = s[i];
                i++;
            }

            else if (s[i] >= '0' && s[i] <= '9') {
                string num = "";
                while (s[i] >= '0' && s[i] <= '9') {
                    num += s[i];
                    i++;
                }
                int Num = stoi(num);
                numStack[++numptr] = Num;
            }

            else if (s[i] == ']') {
                int head = ptr;
                while (Stack[ptr] != '[') {
                    ptr--;
                }
                int tail = ptr + 1;
                ptr--;
                int topnum = numStack[numptr--];
                for (int i = 0; i < 1; i++) {
                    for (int j = tail; j <= head; j++) {
                        Stack[++ptr] = Stack[j];
                    }
                }
                tail--;
                head--;
                for (int i = 1; i < topnum; i++) {
                    for (int j = tail; j <= head; j++) {
                        Stack[++ptr] = Stack[j];
                    }
                }
                i++;
            }
        }
        string ans = "";
        for(int i = 0; i <= ptr; i++){
            ans += Stack[i];
        }

        return ans;
    }
};

// @lc code=start
class Solution {
public:
    string decodeString(string s) {
        // 用 STL 重写了这道题，采用双栈
        stack<char> charStack;
        // 这个栈只存储数字
        stack<int> numStack;
        int n = s.size();
        
        for (int i = 0; i < n;) {
            if (s[i] == '[' || islower(s[i])) {
                charStack.push(s[i]);
                i++;
            }
            else if (isdigit(s[i])) {
                string num = "";
                while (i < n && isdigit(s[i])) {
                    num += s[i];
                    i++;
                }
                int Num = stoi(num);
                numStack.push(Num);
            }
            else if (s[i] == ']') {
                // 提取括号内的字符
                string temp = "";
                while (!charStack.empty() && charStack.top() != '[') {
                    temp = charStack.top() + temp;
                    charStack.pop();
                }
                
                // 弹出 '['
                if (!charStack.empty()) {
                    charStack.pop();
                }
                
                // 获取重复次数
                int repeat = 1;
                if (!numStack.empty()) {
                    repeat = numStack.top();
                    numStack.pop();
                }
                
                // 将重复后的字符串重新压入栈中
                for (int j = 0; j < repeat; j++) {
                    for (char c : temp) {
                        charStack.push(c);
                    }
                }
                i++;
            }
        }
        
        // 构建结果字符串
        string result = "";
        while (!charStack.empty()) {
            result = charStack.top() + result;
            charStack.pop();
        }
        
        return result;
    }
};
// @lc code=end
