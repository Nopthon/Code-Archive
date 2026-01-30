/* Title: AT_dp_i Coins
 *
 * From Codeforces: https://atcoder.jp/contests/dp/tasks/dp_i
 *
 * Translate from Luogu: https://www.luogu.com.cn/problem/AT_dp_i
 *
 * Record: https://atcoder.jp/contests/dp/submissions/72839401
*/

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()	// sort(all(v), cmp);
#define pb push_back					// vector.pb(1);

// #define int long long

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;

// 线性 DP
// 记 dp[i][j] 表示前 i 次掷硬币有 j 次向上的概率
// dp[i][j] = d[i-1][j-1] * p_i + d[i-1][j] * (1 - p_i)
// 累加所有 dp[n][>=n/2] 即可
void solve() {
    int n; cin >> n;
    vector<double> p(n+1); for(int i = 1; i <= n; i++) cin >> p[i]; 
    vector<vector<double>> dp(n+1, vector<double>(n+1, 0));
    dp[1][1] = p[1]; dp[1][0] = 1 - p[1]; 
    for(int i = 2; i <= n; i++){
        for(int j = 0; j <= i; j++){
            dp[i][j] = dp[i-1][j-1] * p[i] + dp[i-1][j] * (1 - p[i]);
        }
    }

    double ans = 0;
    for(int i = (n + 1) / 2; i <= n; i++){
        ans += dp[n][i];
    }

    cout << fixed << setprecision(10) << ans;
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