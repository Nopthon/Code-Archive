/* Title: AT_dp_d Knapsack 1
 *
 * From Codeforces: https://atcoder.jp/contests/dp/tasks/dp_d
 *
 * Translate from Luogu: https://www.luogu.com.cn/problem/AT_dp_d
 *
 * Record: https://atcoder.jp/contests/dp/submissions/72839172
*/

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()	// sort(all(v), cmp);
#define pb push_back					// vector.pb(1);

// #define int long long

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;

// 典型的 0-1 背包 DP 问题，记第 i 个物品的价值为 v_i，体积为 w_i
// dp[i][j] 表示只能放前 i 个物品的情况下，容量为 j 的背包的最大价值
// dp[i][j] = max(dp[i-1][j], dp[i-1][j-w_i] + v_i)
// i 为外层循环，采用滚动数组的思路，可以简化为：
// dp[j] = max(dp[j], dp[j-w_i] + v_i)
// 注意 dp[i][j] 的值 受 dp[i-1][j] 影响，因此背包总容量应该从大（W）到小（w[i]）枚举
// 否则是完全背包问题
void solve() {
    int n, W; cin >> n >> W;
    vector<ll> w(n), v(n), dp(W+1, 0);
    for(int i = 0; i < n; i++) cin >> w[i] >> v[i];

    for(int i = 0; i < n; i++){
        for(ll j = W; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }

    cout << dp[W];
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