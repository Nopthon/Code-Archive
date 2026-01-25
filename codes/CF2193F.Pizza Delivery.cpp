/* Title: CF2193F. Pizza Delivery
 *
 * From Codeforces: https://codeforces.com/contest/2193/problem/F
 *
 * Translate from Luogu: https://www.luogu.com.cn/problem/CF2193F
 *
 * Record: https://codeforces.com/contest/2193/submission/359863706
*/

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()	// sort(all(v), cmp);
#define pb push_back					// vector.pb(1);

// #define int long long

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;

struct node{
	int x, y;
};

ll dis(ll x1, ll y1, ll x2, ll y2){
	return (x2 - x1) + llabs(y2 - y1);
}

// 非常像 Luogu P3842 [TJOI2007] 线段 这道题
// 有生之年我也能场上找原题了（？）
void solve(){
	int n, ax, ay, bx, by; cin >> n >> ax >> ay >> bx >> by;
	vector<node> p(n);
	for (int i = 0; i < n; i++) cin >> p[i].x;
	for (int i = 0; i < n; i++) cin >> p[i].y;

	sort(all(p), [](const node& a, const node& b){
		if(a.x != b.x) return a.x < b.x;
		else return a.y < b.y;
	});

    // valid_x[] 存储存在派送点的 x 坐标
    // L[i], R[i] 存储 x = i 横坐标下 y_min 和 y_max 的值
    // 从而转化为 Luogu P3842 的做法，参考那个题解
	vi valid_x, L, R;

	for (int i = 0; i < n; ) {
		int x = p[i].x;
		int mn = p[i].y, mx = p[i].y;
		int j = i;
		while (j < n && p[j].x == x) {
			mn = min(mn, p[j].y);
			mx = max(mx, p[j].y);
			j++;
		}
		valid_x.pb(x); L.pb(mn); R.pb(mx);
		i = j;
	}

	int m = valid_x.size();
	vector<vector<ll>> dp(m, vector<ll>(2, LLONG_MAX));
	dp[0][0] = dis(ax, ay, valid_x[0], R[0]) + R[0] - L[0];
	dp[0][1] = dis(ax, ay, valid_x[0], L[0]) + R[0] - L[0];

	for (int i = 1; i < m; i++) {
		int span = R[i] - L[i];
		dp[i][0] = min(
			dp[i-1][0] + dis(valid_x[i-1], L[i-1], valid_x[i], R[i]) + span,
			dp[i-1][1] + dis(valid_x[i-1], R[i-1], valid_x[i], R[i]) + span
		);
		dp[i][1] = min(
			dp[i-1][0] + dis(valid_x[i-1], L[i-1], valid_x[i], L[i]) + span,
			dp[i-1][1] + dis(valid_x[i-1], R[i-1], valid_x[i], L[i]) + span
		);
	}

	long long ans = min(
        dp[m-1][0] + dis(valid_x[m-1], L[m-1], bx, by),
        dp[m-1][1] + dis(valid_x[m-1], R[m-1], bx, by)
    );

	cout << ans << "\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int t; 
	cin >> t;			// multi testcases
	// t = 1;				// single testcase
	
	while (t--){
		solve();
	}
	return 0;
}
