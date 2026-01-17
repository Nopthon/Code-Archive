/* Title: CF2184F. Cherry Tree
 *
 * From Codeforces: https://codeforces.com/contest/2184/problem/F
 *
 * Translate from Luogu: https://www.luogu.com.cn/problem/CF2184F
 *
 * Record: https://codeforces.com/contest/2184/submission/357845559
*/

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()	// sort(all(v), cmp);
#define pb push_back					// vector.pb(1);

// #define int long long

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;

// 这里通过位运算来模拟 dp[a] @ dp[b] 的运算过程，其中 return[2:0] 分别表示集合中 {2, 1, 0}
// （这样定义方便位运算）
int fun(int a, int b) {
    // 初始情况，maskbits = dp[v_1]
    if (a == 0) return b;
    int c = 0;
    // 最多 3×3 的运算
    for (int i = 0; i < 3; ++i) {
        if (!((a >> i) & 1)) continue;
        for (int j = 0; j < 3; ++j) {
            if (!((b >> j) & 1)) continue;
            int r = (i + j) % 3;
            c |= (1 << r);
        }
    }
    return c;
}

void DFS(int u, vvi& adj, vi& vis, vi& dp){
	vi childs;
    for(auto& v : adj[u]) if(vis[v] == false) {vis[v] = true; childs.push_back(v); DFS(v, adj, vis, dp);}
    int maskbits = 0;
    for(auto& v : childs) maskbits = fun(maskbits, dp[v]);
    dp[u] = 0b010 | maskbits;
}

// 题目转换为：初始对一个有根树的根节点插旗
// 对于每个非叶插旗节点，我们允许拔出该节点的旗，然后为所有子节点插旗
// 判断总插旗个数是否能被 3 整除
// 构造 dp 方程：记 dp[x] 表示“ x 为根的树的插旗个数有可能会获得哪些余数”，dp[x] ⊆ {2, 1, 0}
// dp[leaf] = {1}
// 定义 dp[a] @ dp[b] 为 dp[a] 和 dp[b] 各自的元素两两相加，得到的集合在模 3 运算下的结果
// 自底向上的状态转移（后序遍历）得到 dp[x] = {1} ⋃ (dp[child_1] @ ... @ dp[child_n])，其中 {1} 表示不操作
// dp[root] ⊆ {0} 则意味着条件可实现
// 实际的实现流程中，我们采用 3 位二进制掩码来完成这件事
void solve() {
    int n; cin >> n;
    vvi adj(n);
    vi dp(n, 0), vis(n, 0);
    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v; u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

	vis[0] = true;
    DFS(0, adj, vis, dp);

    cout << ((dp[0] & 0b1) ? "YES\n" : "NO\n");
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