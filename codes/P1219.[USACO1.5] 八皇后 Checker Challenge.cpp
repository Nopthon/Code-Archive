/* Title: P1219 [USACO1.5] 八皇后 Checker Challenge
 *
 * From Luogu: https://www.luogu.com.cn/problem/P1219
 *
 * Record: https://www.luogu.com.cn/record/258832519
*/

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()	// sort(all(v), cmp);
#define pb push_back					// vector.pb(1);

// #define int long long

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;

int cnt;

void dfs(int row, int n, int& ans, vector<bool>& col, vector<bool>& diag1, vector<bool>& diag2, vector<int>& q) {
    if (row == n) {
		// output 3 ans
		if(cnt > 0){
			cnt--;
			for(auto& x : q) cout << x+1 << " ";
			cout << "\n";
		}
        ans++;
        return;
    }

    for (int c = 0; c < n; c++) {
        if (col[c] || diag1[row - c + n - 1] || diag2[row + c]) continue;
        col[c] = diag1[row - c + n - 1] = diag2[row + c] = true;
		if(cnt > 0) q.push_back(c);
        dfs(row + 1, n, ans, col, diag1, diag2, q);
		if(cnt > 0) q.pop_back();
        col[c] = diag1[row - c + n - 1] = diag2[row + c] = false;
    }
}
void solve(){
	int n; cin >> n;
	int ans = 0; cnt = 3;
    vector<bool> col(n, false), diag1(2 * n - 1, false), diag2(2 * n - 1, false);
	vi q;
    dfs(0, n, ans, col, diag1, diag2, q);
	cout << ans;
}


signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int t; 
	// cin >> t;			// multi testcases
	t = 1;				// single testcase
	
	while (t--){
		solve();
	}
	return 0;
}
