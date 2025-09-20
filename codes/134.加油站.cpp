// For VSCode Coding
#include <bits/stdc++.h>
using namespace std;
//

/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // 我们假定环形一周是可实现的的，并且如题中所述存在唯一解
        // 不考虑中间过程油量耗尽的情况，开完一圈下来，
        // 以油量最少时所在的加油站的下一站作为起点站是贪心的最优解
        // （也就是说要尽可能晚的出现耗油量最大的情况）
        int n = gas.size();
        int sum = 0, minsum = INT_MAX;
        int ans = 0;
        for(int i = 0; i < n; i++){
            int diff = gas[i] - cost[i];
            sum += diff;
            if(minsum > sum){
                minsum = sum;
                ans = i;
            }
        }
        // sum < 0 说明油量总是亏损的，说明无法完成环行
        // 不难证明只要 sum >= 0 就一定存在解
        // 注意 “下一站” 计算时可能会循环到index 0，所以 %n
        return sum < 0 ? -1 : (ans+1)%n;
    }
};
// @lc code=end

