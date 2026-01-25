/* Title: CF2162E. Beautiful Palindromes
 *
 * From Codeforces: https://codeforces.com/contest/2162/problem/E
 *
 * Translate from Luogu: https://www.luogu.com.cn/problem/CF2162E
 *
 * Record: https://codeforces.com/contest/2162/submission/344380019
*/

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()	// sort(all(v), cmp);
#define pb push_back					// vector.pb(1);

// #define int long long

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;

// 给定 a[n] 满足 a[i] <= n，向 a[n] 尾部插入数组 b[k]，也满足 b[i] <= n
// 找到一种 b[k] 的构造，使得 a[n] ~ b[k] 链接后的回文子序列数量最少
// 3 <= k <= n
void solve(){
	int n,k; cin >>n>>k;
	vi has(n+1,0);                  // 1 ~ n 中每个数字的出现次数
	int notshow = n;                // a[n] 中有多少个数字没有出现
	vi vec(n); for(int &x : vec) {
		cin >> x;
		if(has[x] == 0) notshow--;
		has[x]++;
	}
	
    // 如果 1 ~ n 中没有出现过的数字超过两个，考虑 a b c 式循环插入
    // a, b 为两个互异的未出现过的数字，c 为任意的与 a, b 互异的数字
    // 容易得到 b[k] 本身 （也就是 [a,b,c,a,b,c,...]）没有长度 > 1 的回文子序列
    // 构造出的 a b c 按顺序循环插入 a[k] 末端，直到插入 k 个数字
    // 容易得到插入 b[k] 不会产生新的长度 > 1 的回文子序列
    if(notshow >= 2){
		int a,b,c; int cnt = 0;
		int i = 1;
		for(; i <= n; i++){
			if(has[i] == 0) {a = i;i++;break;}
		}
		for(; i <= n; i++){
			if(has[i] == 0) {b = i;i++;break;}
		}
		for(int j = 1; j <= n; j++){
			if(has[j] != 0) {c = j;break;}
		}
		while(cnt <= k){
			cnt++;
			cout << a << " ";
			if(cnt >= k) break;
			cnt++;
			cout << b << " ";
			if(cnt >= k) break;
			cnt++;
			cout << c << " ";
			if(cnt >= k) break;
		}
	}
    // 如果 1 ~ n 中所有的数字都出现过了一次（说明也只会出现一次）
    // 那么 a[n] 成为全排列，全排列本身不产生长度 > 1 的回文子序列
    // 取 a[n] 的前 k 项作为 b[k] 插入
    // 容易得到插入 b[k] 不会产生新的长度 > 1 的回文子序列
    // （以上断言成立的前提是 n >= 3）
	else if(notshow == 0){
		for(int i = 0; i < k; i++){
			cout << vec[i] << " ";
		}
	}
    // 如果 1 ~ n 中存在唯一的一个数字 x 没有出现过，考虑 a b c 式循环插入
    // a 是未出现过的数字 x，且 a, b, c 互异
    // 容易得到 b[k] 本身 （也就是 [a,b,c,a,b,c,...]）没有长度 > 1 的回文子序列
    // 注意到从 [..., a[n-1], b[0], b[1], ...] 开始可能会产生额外的回文子序列（也是唯一的额外产生点）
    // 因此我们要求 b != a[n-1]（并且 != a），此时 c 只要异于 a, b 即可
    // 容易得到插入 b[k] 不会产生新的长度 > 1 的回文子序列
    // （a 和 a[n] 无关，变量名冲突抱歉，实际代码把 a[n] 改成了 vec[n]）
	else if(notshow == 1){
		int a, b, c; 
		for(int i = 1; i <= n; i++){
			if(has[i] == 0) {
				a = i; break;
			}
		}
		for(int j = 0; j < n; j++){
			if(vec[j] != vec[n-1]) {
				b = vec[j]; break;
			}
		}
		for(int j = 0; j < n; j++){
			if(vec[j] != b) {
				c = vec[j]; break;
			}
		}
		int cnt = 0;
		while(cnt <= k){
			cnt++;
			cout << a << " ";
			if(cnt >= k) break;
			cnt++;
			cout << b << " ";
			if(cnt >= k) break;
			cnt++;
			cout << c << " ";
			if(cnt >= k) break;
		}
	} else assert(0);   // impossible
	
	cout << "\n";

	// 上面的逻辑可以化简
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

