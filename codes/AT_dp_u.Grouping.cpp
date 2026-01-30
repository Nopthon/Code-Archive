/* Title: AT_dp_u Grouping
 *
 * From Codeforces: https://atcoder.jp/contests/dp/tasks/dp_u
 *
 * Translate from Luogu: https://www.luogu.com.cn/problem/AT_dp_u
 *
 * Record: https://atcoder.jp/contests/dp/submissions/72841159
*/

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()	// sort(all(v), cmp);
#define pb push_back					// vector.pb(1);

// #define int long long

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;

// 发现 n 很小（不超过 16），对于这种集合划分问题，考虑状压 DP（否则不好记录状态）
// 我们考虑二进制数 mask 的低 n 位表示 n 只兔子在某一个集合中的存在情况
// bit[i] = 1 表示第 i 只兔子在集合中，否则不在
// 首先我们预计算所有可能集合的得分情况：score[mask] = SUM(a[i][j])
// 然后定义 dp[mask] 为对该集合内的兔子进行划分的最高得分
// dp[mask] 可能为不再划分子组的得分值 score[mask]
// 也有可能是分成两个子集后，某种划分方式下的最大值
// 总结成状态转移表达式为：
// dp[mask] = max(score[mask], ALL(dp[submask] + dp[mask ^ submask]))

void solve() {
    int n; cin >> n;
    vector<vector<ll>> a(n+1, vector<ll>(n+1, 0));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];


    // 总共有 1 << n - 1 种 mask
    // 我们要求的是 dp[1 << n - 1] 的值
    int m = (1 << n) - 1;
    vector<ll> dp(1 << n, 0);

    for(int p = 1; p <= m; p++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= i; j++) // 注意这里只取上三角，防止重复计算
                if( (p & (1 << (i-1))) && (p & (1 << (j-1))) )
                    dp[p] += a[i][j];

    for(int mask = 1; mask <= m; mask++)
        // 一种常见的枚举所有非空真子集的写法
        for(int submask = mask & (mask - 1); submask > 0; submask = mask & (submask - 1))
            dp[mask] = max(dp[mask], dp[submask] + dp[mask ^ submask]);

    cout << dp[m];
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int t; 
    // cin >> t;		// multi testcases
    t = 1;			// single testcase
    
    while (t--){
        solve();
    }
    
    return 0;
}