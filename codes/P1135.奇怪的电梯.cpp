/* Title: P1135 奇怪的电梯
 *
 * From Luogu: https://www.luogu.com.cn/problem/P1135
 *
 * Record: https://www.luogu.com.cn/record/258932678
*/

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()	// sort(all(v), cmp);
#define pb push_back					// vector.pb(1);

// #define int long long

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;

void solve() {
    int n, u, v; cin >> n >> u >> v;
    vi floor(n+1);
    for(int i = 1; i <= n; i++) cin >> floor[i];

    vi vis(n+1, 0); vis[u] = 1;
    queue<int> q; q.push(u);
    int ans = 0;

    // BFS，入队时更新 vis 防止重复入队
    while(!q.empty()){
        int len = q.size();
        while(len--){
            int top = q.front();
            q.pop();
            if(top == v){
                cout << ans;
                return;
            }
            
            int l = top-floor[top], r = top+floor[top];
            if(l >= 1 && vis[l] == 0) {q.push(l); vis[l] = 1;}
            if(r <= n && vis[r] == 0) {q.push(r); vis[r] = 1;}
        }
        ans++;
    }

    cout << "-1";
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