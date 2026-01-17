/* Title: CF2149E Hidden Knowledge of the Ancients
 *
 * From Codeforces: https://codeforces.com/contest/2149/problem/E
 *
 * Translate from Luogu: https://www.luogu.com.cn/problem/CF2149E
 *
 * Record: https://codeforces.com/contest/2149/submission/340486328
 * 
*/

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()	// sort(all(v), cmp);
#define pb push_back					// vector.pb(1);

// #define int long long

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;

// 子函数：求 [b,c] 长度
int len(int b, int c){
	return c-b+1;
}

// 子函数：求出 length <= l && diff <= k 的子串个数
int fun(vi&a, int l, int k){
    // 哈希表实现对某一数字出现的个数的 O(1) 级别查找
	unordered_map<int,int> cnt;
	int diff = 0;                               // 不同数字的个数
	int res = 0;                                // 字串个数（返回值）
    // 右指针只需要在左指针操作之后进行自增即可，非常方便讨论
	for(int b = 0, c = 0; c < a.size(); c++){
        // 右指针扩张后，记录新增数据
		if(cnt[a[c]] == 0) diff++;
		cnt[a[c]]++;
        // 在限定情形下的持续左指针收缩
		while(diff > k || len(b, c) > l){
			cnt[a[b]]--;
			if(cnt[a[b]] == 0) diff--;
			b++;
		}
		// 一轮收缩之后，所有以 c 结尾，开头处于 [b,c] 范围的子串都满足所有限制条件
        // 子串个数恰为 len(b,c)，加进答案里
		res += len(b,c);
	}
	return res;	
}

// 题目给出一串数列，求出长度在 [l,r] 范围内，且恰包含 k 个不同数字的子串个数
// 如果采用双指针进行搜索，我们会发现，为了找齐所有的子串，左右指针同时会存在扩张/收缩操作
// 也就是说我们不方便把握双指针的动态调整情况，因此直接的双指针不可取
// 但是我们发现，如果我们只需要求出 “长度 <= r, 不同数字个数 <= k” 的限定子串，难度会小不少
// 此时我只需要在不同数字个数 > k 或者长度 > r 时左指针收缩，右指针只需要 for 向右正常扩张即可
// 之后再利用容斥原理可以得到正确的答案
void solve(){
	int n,k,l,r; cin>>n>>k>>l>>r;
	vi a(n); for(int&x:a) cin >> x;
	
    // 关键：容斥原理的应用
	int ans = fun(a, r, k) - fun(a, l-1, k) + fun(a,l-1, k-1) - fun(a, r, k-1); 
	
	cout << ans << endl; 
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