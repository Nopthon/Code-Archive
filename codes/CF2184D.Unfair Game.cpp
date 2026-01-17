/* Title: CF2184D. Unfair Game
 *
 * From Codeforces: https://codeforces.com/contest/2184/problem/D
 *
 * Translate from Luogu: https://www.luogu.com.cn/problem/CF2184D
 *
 * Record: https://codeforces.com/contest/2184/submission/357567329
*/

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()	// sort(all(v), cmp);
#define pb push_back					// vector.pb(1);

// #define int long long

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;

// 计算组合数 C_n^r
ll C(int n, int r) {
	if (r < 0 || r > n) return 0;
	if (r > n - r) r = n - r;
	ll res = 1;
	for (int i = 1; i <= r; ++i) {
		// 乘除交替计算防止溢出
		res = res * (n - r + i) / i;
	}
	return res;
}

// 对整数 a 进行若干次 -=1 或 /= 2 的计算，要求最小化 a 最终为 0 的次数
// 将数字 a 转换为二进制表示，容易得到：
// 最低位为 0 时，a >>= 1；最低位为 1 时，a -= 1；这是使 a 减小到 0 的最优策略
// 我们发现每个 1 贡献了 2 次运算，每个非前导 0 贡献了 1 次计算，因此：
// a 减小到 0 的最小次数 = a 的长度（由最高位的 1 决定） + 比特 1 的个数 - 1
// 现在题目等价为，求 1 ~ 2^d 中，满足 len(a) + popcount(a) > k + 1 的数字个数
void solve(){
	int n, k; cin >> n >> k;
	int d = log2(n);
	ll ans = 0;

	// 1 ~ 2^d - 1 代表了长度从 1 到 d 的所有数字
	// 对于 len(a) + popcount(a) > k + 1 这个式子，我们从长度 L 开始枚举
	for (int L = 1; L <= d; ++L) {
		// need 代表后 L-1 位至少需要多少 1
		int need = k - L + 1;
		// 如果 need <= 0，说明长度 L 的所有数都满足条件
		if (need <= 0) {
			ans += (1LL << (L - 1));
		// 如果 need <= L - 1，我们在 (1LL << (L - 1)) 的基础上减去不满足条件的部分
		} else if (need <= L - 1) {
			ll s = 0;
			// 后 L-1 位里 1 的个数 t < count_1 的数字个数都要减去
			// 对于从 C_{L-1}^{0} 到 C_{L-1}^{need-1} 的数值都要减去
			for (int w = 0; w < need; ++w)
				s += C(L - 1, w);
			ans += (1LL << (L - 1)) - s;
		}
		// 否则 need > L，即使是 n 个 1 组成的二进制数也不满足条件，忽略
	}
	// 最终对 2^d（1 后面跟 d 个 0）特判一下
	cout << (ans + (d+1 > k ? 1 : 0)) << "\n";
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