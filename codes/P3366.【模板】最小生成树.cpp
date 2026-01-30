/* Title: P3366 【模板】最小生成树
 *
 * From Luogu: https://www.luogu.com.cn/problem/P3366
 *
 * Record: https://www.luogu.com.cn/record/259384060
*/

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()	// sort(all(v), cmp);
#define pb push_back					// vector.pb(1);

// #define int long long

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;

// 边信息结构体
struct edge {
    int u; int v; int w;
};

// 并查集模板
vi dsu;

int find(int x){
    return (dsu[x] == x ? x : (dsu[x] = find(dsu[x])) );
}

void unite(int src, int dst) {
    dsu[find(src)] = find(dst);
}

// 主函数
void kruskal(int n, int m){

    vector<edge> edges(m);

    for(int i = 0; i < n; i++) dsu[i] = i;
    for(int i = 0; i < m; i++){
        int u,v,w; cin>>u>>v>>w;
        edges[i] = {u-1,v-1,w};
    }

    std::sort(edges.begin(), edges.end(), [](const edge& a, const edge& b) {
        return a.w < b.w;
    });

    int total = 0, edge_cnt = 0;
    for(int i = 0; i < m; i++){
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        if(find(u) != find(v)){
            unite(u, v);
            total += w;
            edge_cnt++;
            if (edge_cnt == n - 1) break;
        }
    }
    // 确保加了 n-1 条边
    if(edge_cnt == n-1) cout << total; else cout << "orz";
}

void solve() {
    int n, m; cin >> n >> m;
    dsu.resize(n);
    kruskal(n, m);
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