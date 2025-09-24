// For VSCode Coding
#include <bits/stdc++.h>
using namespace std;
//

/*
 * @lc app=leetcode.cn id=2327 lang=cpp
 *
 * [2327] 知道秘密的人数
 */

// 最纯粹的模拟，时间复杂度达到 O(2^n)，TLE
// 没有 % MOD 的原因是这个做法不方便中途取模
class Bad_Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        deque<int> dq(1,0);
        while(n--){
            for(int i = 0; i < dq.size(); i++){
                dq[i]++;
            }
            while(!dq.empty() && dq.front() > forget){
                dq.pop_front();
            }
            for(int i = 0; i < dq.size(); i++){
                if(dq[i] > delay){
                    dq.push_back(1);
                }
            }
        }
        return dq.size();

    }
};

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        // afterdays[i] 滚动的是处于 “了解秘密之后 i 天” 的人数
        // 时间复杂度 O(forget * n)
        // partsum 记录 [delay, forget) 的区间段人数
        const int MOD = 1e9+7;
        int partsum = 0;
        int offset = 0;
        // 多开一位，方便后续的前缀和优化
        vector<int> afterdays(forget+1);
        // day1
        afterdays[0] = 1;
        n--;
        // day2+
        while(n--){
            // 所有人day++，变成了offset右移一位
            offset = (offset - 1 + (forget+1)) % (forget+1);
            // 利用区间和进行计算优化
            partsum = ((partsum + afterdays[(delay+offset) % (forget + 1)] - afterdays[(forget+offset) % (forget + 1)]) % MOD + MOD) % MOD;
            afterdays[offset] = partsum;
        }
        // 统计总人数
        int ans = 0;
        for(int i = 0; i < forget; i++){
            ans = (ans + afterdays[(i+offset) % (forget + 1)]) % MOD;
        }
        return ans;
    }
};
// @lc code=end

