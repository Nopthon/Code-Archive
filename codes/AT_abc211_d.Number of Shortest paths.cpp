/* Title: AT_abc211_d Number of Shortest paths
 *
 * From AtCoder: https://atcoder.jp/contests/abc211/tasks/abc211_d
 *
 * Translate from Luogu: https://www.luogu.com.cn/problem/AT_abc211_d
 *
 * Record: https://atcoder.jp/contests/abc211/submissions/72825105
*/

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()    // sort(all(v), cmp);
#define pb push_back                    // vector.pb(1);
#define MOD 1000000007

// #define int long long

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;

struct edge {
    int v; ll w; // 目标 and 权 
};

vector<bool> vis;
vector<ll> dis;
vector<vector<edge>> chart;

// 额外维护一个路线数数组，维护方式如下
vector<ll> way;

void dijkstra(int n, int s){
    dis[s] = 0;
    way[s] = 1;
    priority_queue<pair<ll,int>, vector<pair<ll,int> >, greater<pair<ll,int> > > pq;
    pq.push({0,s});

    while(!pq.empty()){
        auto top = pq.top();
        int u = top.second;
        pq.pop();

        if(vis[u]) continue; vis[u] = true;

        // 不能在这里剪枝
        // if(u == n) break;

        for(auto& c: chart[u]){
            if(dis[u] + c.w < dis[c.v]) {
                dis[c.v] = dis[u] + c.w;
                pq.push({dis[c.v], c.v});
                // 发现了更短路，重置
                way[c.v] = way[u];
            } else if(dis[u] + c.w == dis[c.v]){
                // 同为最短路，累加
                way[c.v] = (way[c.v] + way[u]) % MOD;
            }
        }
    }
    return;
}

// 最短路的子路径也是最短路
// Dijkstra 对点扩张时，同步更新路线个数的数组即可（与距离数组同步更新）
void solve() {
    int n, m; cin >> n >> m;
    chart.resize(n+1);
    vis.resize(n+1, false);
    dis.resize(n+1, LLONG_MAX);
    way.resize(n+1, 0);
    for(int i = 1; i <= m; ++i){
        int u,v;
        cin >> u >> v;
        chart[u].push_back({v,1});
        chart[v].push_back({u,1});
    }

    dijkstra(n,1);

    cout << way[n];
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int t; 
    // cin >> t;        // multi testcases
    t = 1;            // single testcase
    
    while (t--){
        solve();
    }
    
    return 0;
}