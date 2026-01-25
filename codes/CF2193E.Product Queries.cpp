/* Title: CF2193E. Product Queries
 *
 * From Codeforces: https://codeforces.com/contest/2193/problem/E
 *
 * Translate from Luogu: https://www.luogu.com.cn/problem/CF2193E
 *
 * Record: https://codeforces.com/contest/2193/submission/359871356
*/

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()	// sort(all(v), cmp);
#define pb push_back					// vector.pb(1);

// #define int long long

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;

// BFS 改进，转换为图上的最短路搜索问题
// 因为每条边的边权都为 1，所以 BFS 优于 Dijkstra
void solve(){
	int n; cin >> n;
    // 对数组 a 排序，去重以降低遍历量
	vi a(n); for(int& x : a) cin >> x;
	sort(all(a));
	auto p = unique(a.begin(), a.end());
	a.erase(p, a.end());


	vi dis(n+1, -1); queue<int> q;
	for(int& x : a){
		if(dis[x] == -1){
			dis[x] = 1; q.push(x);
		}
	}

	while(!q.empty()){
		int x = q.front(); q.pop();

		for(int& y : a){
			ll xy = (ll)x*y;
			if(xy > n) break;
			if(dis[xy] == -1){
				dis[xy] = dis[x] + 1; q.push(xy);
			}
		}
	}

	for(int i = 1; i <= n; i++) cout << dis[i] << " ";
	cout << "\n";
}

// 这是完全背包 DP 的做法，时间复杂度 O(mn)
// 其中 m 是去重后 a 的大小
// TLE
void plain_solve(){
    int n; cin >> n;
    // 对数组 a 排序，去重以降低遍历量
	vi a(n); for(int& x : a) cin >> x;
	sort(all(a));
	auto p = unique(a.begin(), a.end());
	a.erase(p, a.end());

    // 初始化背包，每个 a 中存在的数字对应的数字个数为 1
	vi dp(n+1, INT_MAX);
    for(int& v : a) if (v <= n) dp[v] = 1;

	for(int x = 1; x <= n; x++){
		if(dp[x] == INT_MAX) continue;  // 不可达
        // 尝试添加 a 中的数字 y 
		for(int& y : a){
			if((ll)x*y <= n){
				dp[x*y] = min(dp[x*y], dp[x] + 1);
			}
		}
	}

	for(int i = 1; i <= n; i++){
		cout << (dp[i] == INT_MAX ? -1 : dp[i]) << " ";
	}
	cout << "\n";
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

// 官方 Solution 使用的是 dp[j] = min(dp[j], dp[i] + dp[j/i]) 的动态规划解法
// mol