/* Title: CF20C Dijkstra?
 *
 * From Codeforces: https://codeforces.com/contest/20/problem/C
 *
 * Translate from Luogu: https://www.luogu.com.cn/problem/CF20C
 *
 * Record: https://codeforces.com/contest/20/submission/360456227
*/

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()	// sort(all(v), cmp);
#define pb push_back					// vector.pb(1);

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

// 额外维护一个前缀数组，对于最短路上的 u -> v，有 prev[v] = u
vi Prev;

void dijkstra(int n, int s){
    dis[s]=0;
    priority_queue<pair<ll,int>, vector<pair<ll,int> >, greater<pair<ll,int> > > pq;
    pq.push({0,s});

    while(!pq.empty()){
        auto top = pq.top();
		int b = top.second;
        pq.pop();

        if(vis[b]) continue; vis[b] = true;

        if(b == n) break;

        for(auto& c: chart[b]){
            if (dis[b] + c.w < dis[c.v]) {
                dis[c.v] = dis[b] + c.w;
                Prev[c.v] = b;  // 记录前缀信息
                pq.push({dis[c.v], c.v});
            }
        }
        
    }
    return;
}

// Dijkstra? Dijkstra!
// 在模板 Dijkstra 的基础上再加上最短路的存储即可
void solve() {
    int n, m; cin >> n >> m;
    chart.resize(n+1);
    vis.resize(n+1, false);
    dis.resize(n+1, LLONG_MAX);
    Prev.resize(n+1, -1);
    for(int i = 1; i <= m; ++i){
        int u,v; ll w;
        cin >> u >> v >> w;
        chart[u].push_back({v,w});
        chart[v].push_back({u,w});
    }

    dijkstra(n,1);

    if(dis[n] == LLONG_MAX){
        cout << -1 << endl; return;
    }

    vector<ll> ans;

    // 倒序回溯路线，倒转后得到答案
    for(int v = n; v != -1; v = Prev[v]) ans.pb(v);
    reverse(all(ans));

    if(!ans.empty()){
        for(ll& x : ans) cout << x << " ";
    } else cout << -1;
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