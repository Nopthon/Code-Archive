// For VSCode Coding
#include <bits/stdc++.h>
using namespace std;
//

/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // 一个矩形的确定方式是：选定一个柱子作为固定高度，尝试向两边延伸宽度，宽乘高得到面积
        // 考虑维护一个由高度决定的单调递增栈，栈本身存储索引值：
        // 对于栈中的每一个索引值，其左侧的值就是 “左边界索引 l”
        // 当一个索引被弹出时，使它被弹出的索引就是 “右边界索引 r”
        // 对每一个高为 h 的柱子，其向两边延伸的最大宽度为 (r-l-1)
        // （为了确保每根柱子都被弹出，最后面要加一个高度为 0 的占位柱子）
        int ans = 0;
        heights.push_back(0);
        stack<int> st; st.push(0);
        for(int i = 1; i < heights.size(); i++){
            if(heights[i] >= heights[st.top()]){
                st.push(i);
            }
            else {
                while (!st.empty() && heights[i] < heights[st.top()]){
                    int h = heights[st.top()];
                    st.pop();
                    // 注意空栈的特殊处理
                    int width = i - (st.empty() ? -1 : st.top()) - 1;
                    ans = max(ans, h * width);
                }
                st.push(i);
            }
        }
        return ans;
    }
};
// @lc code=end

