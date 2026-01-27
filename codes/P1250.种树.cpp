/* Title: P1250 种树
 *
 * From Luogu: https://www.luogu.com.cn/problem/P1250
 *
 * Record: https://www.luogu.com.cn/record/259174594
*/

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()	// sort(all(v), cmp);
#define pb push_back					// vector.pb(1);

// #define int long long

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;

struct info{
	int b, e, t;
};

// 考虑优先在重叠程度最高的区域内种树（贪心）
void solve() {
	int n, h; cin >> n >> h;
	vector<info> a(h); for(info& x : a) cin >> x.b >> x.e >> x.t;
	// 右端点从小到大（优先），区间长度从短到长（其次）排序
	// 保证更早结束，长度更短的区间优先满足植树需求
	// 同时该排序结果下，重合区间集中在每个区间的右端
	sort(all(a), [](const info& a, const info& b){
		if(a.e != b.e) return a.e < b.e;
		else return a.b > b.b;
	});
	
	// 记录每个位置是否已经种树
	vector<bool> planted(n + 1, false);
	int ans = 0;

	// 遍历每个区间
	for(info& x : a){
		int cnt = 0;
		// 统计区间内已有的树
		for(int i = x.b; i <= x.e; i++){
			if(planted[i]) cnt++;
		}

		if(cnt >= x.t) continue;
		
		// 区间内从右往左种树
		cnt = x.t - cnt;
		for(int i = x.e; i >= x.b && cnt > 0; --i){
			if(!planted[i]){
				planted[i] = 1;
				ans++; cnt--;
			}
		}
	}

	cout << ans;
	
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