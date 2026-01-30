/* Title: AT_dp_f LCS
 *
 * From Codeforces: https://atcoder.jp/contests/dp/tasks/dp_f
 *
 * Translate from Luogu: https://www.luogu.com.cn/problem/AT_dp_f
 *
 * Record: https://atcoder.jp/contests/dp/submissions/72840530
*/

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()	// sort(all(v), cmp);
#define pb push_back					// vector.pb(1);

// #define int long long

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;

// LCS 模板题
// dp[i][j] 表示 s[1..i] 与 t[1..i] 的 LCS 长度， dp[0][0] = 0
// 如果 s[i] = t[j]，则 dp[i][j] = dp[i-1][j-1] + 1;
// 否则 dp[i][j] = max(dp[i-1][j], dp[i][j-1]) 
// 除此以外，我们还需要记录 LCS 本身，我们记录状态转移的方向
// dir[i][j] 用来记录每个状态是如何得到的，初始记为 -1
// dir[i][j] = 0 对应 s[i] == t[j] 的更新
// dir[i][j] = 1 对应 s[i] != t[j] 时，dp[i-1][j] 更大的情况（最优解不含 s[i]）
// dir[i][j] = 1 对应 s[i] != t[j] 时，dp[i][j-1] 更大的情况（最优解不含 t[j]）
// dir 数组不是必要的，空间换时间

void solve() {
    string s, t; cin >> s >> t;
    int n = s.length(), m = t.length();
    s = "#" + s; t = "@" + t;
    vvi dp(n+1, vi(m+1, 0));
    vvi dir(n+1, vi(m+1, -1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s[i] == t[j]){
                dp[i][j] = dp[i-1][j-1] + 1;
                dir[i][j] = 0;
            }
            else if(dp[i-1][j] >= dp[i][j-1]){
                dp[i][j] = dp[i-1][j];
                dir[i][j] = 1;
            }
            else{
                dp[i][j] = dp[i][j-1];
                dir[i][j] = 2;
            }
        }
    }

    // 回溯构造 LCS
    // 如果不构造 dir 数组，也可以用注释中的判断方式
    string lcs = "";
    for(int i = n, j = m; i > 0 && j > 0; ){
        switch(dir[i][j]){
        case 0:     // s[i] == t[j]
            lcs = s[i] + lcs;
            i--; j--; break;
        case 1:     // dp[i-1][j] >= dp[i][j-1]
            i--; break;
        case 2:     // dp[i-1][j] < dp[i][j-1]
            j--; break;
        default:
            i = 0; j = 0; break;
        }
    }

    cout << lcs;
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