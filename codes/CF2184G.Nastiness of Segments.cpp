/* Title: CF2184G. Nastiness of Segments
 *
 * From Codeforces: https://codeforces.com/contest/2184/problem/G
 *
 * Translate from Luogu: https://www.luogu.com.cn/problem/CF2184G
 *
 * Record: https://codeforces.com/contest/2184/submission/358303612
*/

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()	// sort(all(v), cmp);
#define pb push_back					// vector.pb(1);

// #define int long long

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;


/* 线段树模板 */

vi tree;

void build(int node, int l, int r){
	if(l == r){
		cin >> tree[node];
		return;
	}

	int mid = (l+r) >> 1;
	int left = node << 1;
	build(left, l, mid);
	build(left + 1, mid + 1, r);
	tree[node] = min(tree[left], tree[left+1]);
}

int query(int node, int l, int r, int ql, int qr){
	if(ql <= l && r <= qr){
		return tree[node];
	}
	int mid = (l+r) >> 1;
	int left = node << 1;
	int res = INT_MAX;
	if(ql <= mid){
		res = min(res, query(left, l, mid, ql, qr));
	} 
	if(qr > mid){
		res = min(res, query(left+1, mid+1, r, ql, qr));
	}
	return res;
}

void update(int node, int l, int r, int pos, int val) {
	if(l == r){
		tree[node] = val;
		return;
	}

	int mid = (l+r) >> 1;
	int left = node << 1;
	if(pos <= mid){
		update(left, l, mid, pos, val);
	} else {
		update(left+1, mid+1, r, pos, val);
	}
	tree[node] = min(tree[left], tree[left+1]);
}

// 二分找 D 应该存在的位置
bool nastiness(int n, int l, int r){
	int dl = 0, dr = r-l;
	int ans = -1;

	while (dl <= dr){
		int mid = (dl + dr) >> 1;
		if(query(1, 1, n, l, l + mid) <= mid){
			ans = mid;
			dr = mid - 1;
		} else dl = mid + 1;
	}

	if(ans == -1) return false;

	// 最后需要确认二分得到的 <= 是否实际为 ==
	return query(1, 1, n, l, l + ans) == ans;
}


// 给定一个允许单点修改的数组，查询区间 [l, r] 中满足 min(a_l, ... , a_{l+d}) = d (0 <= d <= r-l) 的 d 的数量
// 我们固定 l，逐渐增大 d，容易发现 min(a_l, ... , a_{l+d}) 是非增函数，而 d 是严格递增的，因此等式有唯一解 D
// 因此对 [l, r] 的区间查询结果答案只有可能是 0 （或 1），对于 0 <= d < D 答案为 0，对于 D <= d <= r-l 答案为 1（可能在区间内无解）
// 考虑二分找出 D 的位置（或者无解），区间最小值 RMQ 用线段树维护
void solve() {
	int n, q; cin >> n >> q;

	tree.resize(4*n, 0);
	build(1, 1, n);

	while(q--){
		int a, x, y;
		cin >> a >> x >> y;
		if(a == 1) update(1, 1, n, x, y);
		else cout << nastiness(n, x, y) << "\n";
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int t; 
	cin >> t;		// multi testcases
	// t = 1;			// single testcase
	
	while (t--){
		solve();
	}
	
	return 0;
}