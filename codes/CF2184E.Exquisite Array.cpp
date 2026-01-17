/* Title: CF2184E. Exquisite Array
 *
 * From Codeforces: https://codeforces.com/contest/2184/problem/E
 *
 * Translate from Luogu: https://www.luogu.com.cn/problem/CF2184E
 *
 * Record: https://codeforces.com/contest/2184/submission/357603248
*/

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()	// sort(all(v), cmp);
#define pb push_back					// vector.pb(1);

// #define int long long

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;

// 方便根据值找下标
typedef struct info{
	int idx; int cnt; 
} info;

// 计算长度 L 的串的子串个数
ll calc(ll L){
	return (L)*(L+1)/2;
}

// 用于并查集
vi dsu, sz;

// total 用来累计符合条件的字串个数，使用全局变量方便修改
ll total;

// 并查集的查操作
int find(int x){
	return (dsu[x] == x ? x : (dsu[x] = find(dsu[x])) );
}

// 并查集的并操作，按 size 合并（因为需要记录 size 大小）
void unite(int x, int y){
	x = find(x);
	y = find(y);
	if (x == y) return;

    // 减去合并前两段序列各自的贡献
	total -= (calc(sz[x]) + calc(sz[y]));

	if(sz[x] < sz[y]) swap(x, y);
	dsu[y] = x;
	sz[x] += sz[y];

    // 加上合并后序列的贡献
	total += calc(sz[x]);
}


// 给定一个长度为 n 的排列 p，对每个 k 从 1 到 n−1，统计所有相邻元素差值至少为 k 的子数组的个数
// 初步思路是对差值数组 diff[n-1]，对每个 k 进行一轮遍历，时间复杂度 O(n^2)
// 注意到当 k 从 n-1 减小到 1 时，满足条件的 diff 段是只增不减的，从 diff 值最大的元素开始扩散
// 于是考虑对 diff[n-1] 从大到小排序（并储存下标便于位置的对应），从左到右遍历更新
// 符合条件的 diff 段通过并查集维护，同时计算子数组的个数
//（想象一个柱状图，k 从上往下扫描，k 上面的部分参与计算）
void solve(){
	int n; cin >> n;
    // 初始化并查集等
	dsu.clear(); sz.clear(); dsu.resize(n-1); sz.resize(n-1);
    for(int i = 0; i < n-1; i++) {
		dsu[i] = i;
		sz[i] = 1;
	}
	
	vector<info> diff(n-1);
    vi ac(n-1, 0);
	total = 0;
    // 对原始输入求差建立 diff 数组
	int n1, n2; cin >> n2;
	for(int i = 0; i < n-1; i++){
		n1 = n2;
		cin >> n2;
        // 用结构体同时存储下标和差值
		diff[i] = {i, abs(n2-n1)};
	}

    // 按照 diff 值排序（从高到低）
	sort(diff.begin(), diff.end(), [](const info& a, const info &b) {return a.cnt > b.cnt;});

    // diff_ptr 记录目前遍历到的 diff 元素位置，ans 记录答案
	int diff_ptr = 0; vector<ll> ans(n, 0);

    // k 从高到低遍历
	for(int k = n-1; k >= 1; k--){
		// 只要 diff 没有遍历完全，就一直遍历到 diff >= k
		while(diff_ptr < n-1 && diff[diff_ptr].cnt >= k){
            // 取下标
			int idx = diff[diff_ptr].idx;
            // 标记该下标已经被遍历过
			ac[idx] = true; total += 1;

            // 如果这个元素左右两侧都有已经被标记的元素，进行并操作
			if(idx > 0 && ac[idx - 1]) unite(idx - 1, idx);
			if(idx + 1 < n - 1 && ac[idx + 1]) unite(idx, idx + 1);
            // 遍历指针前进
			diff_ptr++;
		}
        // 记录答案
		ans[k] = total;
	}
    
    // 输出答案
	for(int i = 1; i <= n-1; i++) cout << ans[i] << " "; cout << "\n";
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