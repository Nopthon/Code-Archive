/* Title: P5663 [CSP-J 2019] 加工零件
 *
 * From Luogu: https://www.luogu.com.cn/problem/P5663
 *
 * Record: https://www.luogu.com.cn/record/259837935
*/

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()	// sort(all(v), cmp);
#define pb push_back					// vector.pb(1);

// #define int long long

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;

// 工人 x 需要第 L 阶段的零件，是否需要工人 1 提供原材料
// 容易得到问题的解答为：是否存在 1 <-> x 的一条长度为 L 的路径（边权全部为 1）
// 不难发现，由于可以在两点间重复移动，因此如果存在长度 L 的路径，就一定存在 L+2k 的路径
// 但是存在长度 L 的路径，不一定存在 L+2k+1 的路径
// 因此思路很明显了，分别求奇数和偶数下的单源最短路，然后比较 L 与奇偶最短路的值
// 因为边权为 1，所以 BFS 即可
void solve() {
    int n, m, Q; cin >> n >> m >> Q;
    vvi adj(n+1); 
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        adj[u].pb(v); adj[v].pb(u);
    }

    vvi d(2, vi(n+1, INT_MAX)); d[0][1] = 0;
    queue<pair<int, int>> q;    // {low_bit, node}
    q.push({0, 1});
    while(!q.empty()){
        auto [lb, u] = q.front(); q.pop();
        for(auto& v : adj[u]){
            if(d[lb^1][v] == INT_MAX){
                d[lb^1][v] = d[lb][u] + 1;
                q.push({lb^1, v});
            }
        }
    }

    while(Q--){
        int a, L; cin >> a >> L;
        if(d[0][a] != INT_MAX && L >= d[0][a] && (L - d[0][a]) % 2 == 0 ||
            d[1][a] != INT_MAX && L >= d[1][a] && (L - d[1][a]) % 2 == 0
        ) cout << "Yes\n";
        else cout << "No\n";
    }
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