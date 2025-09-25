/* Title: P3842 [TJOI2007] 线段
 *
 * From Luogu: https://www.luogu.com.cn/problem/P3842
 *
 * Record: https://www.luogu.com.cn/record/236869471
*/

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()	// sort(all(v), cmp);
#define pb push_back					// vector.pb(1);
#define dis(a,b) (abs((a) - (b)))

// #define int long long

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;

void solve() {
    int n;
    cin >> n;
    // dp 数组记录截至当前层的最短路长度
    // dp[i][0] 与 dp[i][1] 分别为抵达线段最左端/最右端的最短路
    // line[i][0] 与 line[i][1] 分别为每一层线段的左右端点
    vvi dp(n, vi(2)), line(n, vi(2));

    for(vi &lr : line)
        cin >> lr[0] >> lr[1];
        
    dp[0][0] = 2*line[0][1] - line[0][0] - 1;
    dp[0][1] = line[0][1] - 1;

    for(int i = 1; i < n; i++){
        // 将 abs 宏定义为 dis 有助于理解，注意向下一层也算 1 单位路程
        dp[i][0] = min(dp[i-1][0] + dis(line[i-1][0], line[i][1]) + dis(line[i][1], line[i][0]) + 1, dp[i-1][1] + dis(line[i-1][1], line[i][1]) + dis(line[i][1], line[i][0]) + 1),
        dp[i][1] = min(dp[i-1][0] + dis(line[i-1][0], line[i][0]) + dis(line[i][1], line[i][0]) + 1, dp[i-1][1] + dis(line[i-1][1], line[i][0]) + dis(line[i][1], line[i][0]) + 1);
    }
    // 加上到 (n,n) 的路线然后取更短的路线
    cout << min(dp[n-1][0] + dis(n, line[n-1][0]), dp[n-1][1] + dis(n, line[n-1][1]));
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