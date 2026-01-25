/* Title: P1020 [NOIP 1999 提高组] 导弹拦截
 *
 * From Luogu: https://www.luogu.com.cn/problem/P1020
 *
 * Record: https://www.luogu.com.cn/record/236687979
 */

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()  // sort(all(v), cmp);
#define pb push_back                   // vector.pb(1);

// #define int long long

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;

// 先翻译一遍题干：对于一个数列，求出其最长不上升子数列的长度
// 以及至少能用几个最长不上升子序列覆盖整个数列
void plain_solve() {
    // O(n^2) 朴素做法（只考虑第一小问）
    // 不妨记以原数列（长度为 n）第 i 项为结尾的最长不上升子数列的长度为 dp[i]
    // 我们最终想要求出 max(dp[i]) (i = 1, ..., n)
    // 考虑 dp[i] 会受到什么影响？
    // 对于 i 前面的所有项 j ，只要 arr[j] >= arr[i]，说明 arr[i] 可以加在
    // arr[j] 后面 从而可以尝试构成一个更长的递减子数列
    // 即 dp[i] = max(dp[i], dp[j]+1), for all (j < i && arr[i] <= arr[j])
    vi arr;
    int num, maxLen = 1;
    // 对未知数量的整数的一种读入方式
    while (cin >> num) {
        arr.pb(num);
        if (cin.get() == '\n') break;
    }

    vi dp(arr.size(), 1);

    for (int i = 1; i < arr.size(); i++) {
        for (int j = 0; j < i; j++)
            if (arr[i] <= arr[j])
                dp[i] = max(dp[i], dp[j] + 1);

        maxLen = max(maxLen, dp[i]);
    }
    cout << maxLen << endl;
    // 第二小问略
}


void solve() {
    // 对于第一问的 O(nlog n) 做法
    // 我们不妨维护一个尽可能长的不上升序列 dp
    // dp[i] 表示长度为 i+1 的不上升子序列的最后一个元素的最大可能值
    // （为什么存储最大值？因为更大的末尾值可以给后续数字更多接上的机会）
    // （从而最大化 dp 的长度，得到我想要的答案）
    // 做法：遍历 arr，如果 arr[i] <= dp.back() （包括 dp 为空的情况）
    // 则将 arr[i] 添加到 dp 的末尾
    // 否则，则将 arr[i] 替换掉 dp 中第一个比它小的元素
    // 这样能尽可能地 “给后续数字更多接上的机会”
    // 最终 dp 的大小就代表了最长不上升子序列的长度（但并不是这个序列本身）
    vi arr;
    int num;
    while (cin >> num) {
        arr.pb(num);
        if (cin.get() == '\n') break;
    }
    // 第一问：
    vi dp1;
    for (int num : arr) {
        if (dp1.empty() || num <= dp1.back())
            dp1.pb(num);
        //【找到第一个小于当前元素的位置】
        else {
            auto it = upper_bound(dp1.begin(), dp1.end(), num, greater<int>());
            *it = num;
        }
    }
    // 对于第二问，根据 Dilworth 定理：
    // 任何有限偏序集的最小链划分等于其最大反链的大小
    // 对于 “导弹拦截” 问题，我们可以理解为：
    // 只有在遇到比之前所有导弹都高的导弹时才需要加装拦截系统，而这种情况正好对应着严格递增子序列的“断点”
    // 所以第二问转化为了求 “最长严格递增子序列” 的长度（和第一问相反）
    vi dp2;
    for (int num : arr) {
        if (dp2.empty() || num > dp2.back())                    // 改动 1
            dp2.pb(num);
        else {
            //【找到第一个大于等于当前元素的位置】
            auto it = lower_bound(dp2.begin(), dp2.end(), num); // 改动 2
            *it = num;
        }
    }
    // 输出答案
    cout << dp1.size() << endl << dp2.size();
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    // cin >> t;		// multi testcases
    t = 1;			// single testcase

    while (t--) {
        solve();
    }

    return 0;
}

// LeetCode 第 300 题也是求 LIS 的题目