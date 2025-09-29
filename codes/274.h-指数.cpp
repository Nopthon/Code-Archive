// For VSCode Coding
#include <bits/stdc++.h>
using namespace std;
//

/*
 * @lc app=leetcode.cn id=274 lang=cpp
 *
 * [274] H 指数
 */

class Plain_Solution {
public:
    int hIndex(vector<int>& citations) {
        // 容易得出：如果 h0 是最大的 h 指数，那么 0~h0 都可以是 h 指数
        // 考虑二分，这里给出一个非常 STL 的间接写法
        // 时间复杂度是二分查找的 O(log(n)) 乘上 count_if 的 O(n)，即 O(nlog n) 
        // 空间复杂度常数级别
        int l = 0, r = citations.size();
        int ans = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int cnt = count_if(citations.begin(), citations.end(),
                                [mid](int val) { return val >= mid; });
            if(cnt < mid){
                r = mid - 1;
            }
            else{
                ans = mid; 
                l = mid + 1;
            }
        }
        return ans;
    }
};

// @lc code=start
class Solution {
public:
    int hIndex(vector<int>& citations) {
        // 如果追求时间复杂度的话，我们不妨构造一个计数数组，对 citations 进行桶计数
        // 从高到低扫描到的第一个正确的 h 指数就是正确答案
        // 时间复杂度 O(n)，对于 n <= 5000 的数据似乎没什么区分度
        int n = citations.size();
        vector<int> cnt (n+1, 0);
        for(int &x : citations){
            x <= n ? cnt[x]++ : cnt[n]++;
        }

        int counts = 0;
        for(int i = n; i >= 0; --i){
            counts += cnt[i];
            if(counts >= i) return i;
        }

        return 0;
    }
};
// @lc code=end
