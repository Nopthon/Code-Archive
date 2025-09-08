// For VSCode Coding
#include <bits/stdc++.h>
using namespace std;
//

/*
 * @lc app=leetcode.cn id=1792 lang=cpp
 *
 * [1792] 最大平均通过率
 */

// @lc code=start
class Solution {
private:
    struct Class {
        int pass;
        int total;
    };

struct cmp {
    bool operator()(const Class& a, const Class& b) {
        return (double)(a.pass + 1) / (a.total + 1) - (double)a.pass / a.total < (double)(b.pass + 1) / (b.total + 1) - (double)b.pass / b.total;
    }
};

public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
    // 优先队列始终将 (pass+1)/(total+1) - pass/total 最大值 置顶
    priority_queue<Class, vector<Class>, cmp> pq;
    double ans = 0;
    for(int i = 0; i < classes.size(); i++){
        pq.push({classes[i][0], classes[i][1]});
        ans += (double)classes[i][0] / classes[i][1];
    }
    while(extraStudents>0){
        Class tmp = pq.top();
        pq.pop();
        ans -= (double)tmp.pass/tmp.total;
        tmp.pass++; tmp.total++;
        ans += (double)tmp.pass/tmp.total;
        pq.push(tmp);
        extraStudents--;
    }
    return ans / classes.size();


    }
};
// @lc code=end

