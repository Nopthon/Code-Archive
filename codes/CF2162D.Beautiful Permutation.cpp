/* Title: CF2162D. Beautiful Permutation
 *
 * From Codeforces: https://codeforces.com/contest/2162/problem/D
 *
 * Translate from Luogu: https://www.luogu.com.cn/problem/CF2162D
 *
 * Record: https://codeforces.com/contest/2162/submission/344300307
*/

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()	// sort(all(v), cmp);
#define pb push_back					// vector.pb(1);

// #define int long long

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;


// 接触的第一道交互题
// 已知 a[n] 中的 a[l] ~ a[r] 数值被人为加 1
// 每次可以询问任意 p ~ q 区间的“原区间和”或“现区间和”
// 在限定次数的询问内得到被人为加 1 的区间边界 l r
void solve(){
	int n; cin >> n;
	int l = 0, r = n;
    // 先获取整个数组中被修改的长度
	cout << "1 1 " << n << "\n";
	cout.flush();
	ll x; cin >> x;
	
	cout << "2 1 " << n << "\n";
	cout.flush();
	ll y; cin >> y;
    // odiff 为被修改的总长度
	ll odiff = y-x;

    // 找到右边界 r 
	int left = 1, right = n, mid;
	while(left <= right){
		mid = left + (right - left) /2;
		cout << "1 1 " << mid << "\n";
		cout.flush();
		cin >> x;
		
		cout << "2 1 " << mid << "\n";
		cout.flush();
		cin >> y;
        // 如果 0 ~ r 范围的修改前后差值小于总差值
        // 说明 r < real_r，收缩左边界
		if(y-x < odiff){
			left = mid +1;
		}
        // 否则收缩右边界
		else {right = mid - 1; r = mid;}
	}

    // 根据 odiff 的值计算左边界
	l = r - odiff + 1;

	cout << "! " << l << " " << r << "\n";
	cout.flush();

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