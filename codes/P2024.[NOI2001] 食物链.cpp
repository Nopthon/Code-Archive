/* Title: P2024 [NOI2001] 食物链
 *
 * From Luogu: https://www.luogu.com.cn/problem/P2024
 *
 * Record: https://www.luogu.com.cn/record/259397357
*/

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()	// sort(all(v), cmp);
#define pb push_back					// vector.pb(1);

// #define int long long

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;

// 并查集模板
vi dsu;

int find(int x){
    return (dsu[x] == x ? x : (dsu[x] = find(dsu[x])) );
}

void unite(int src, int dst) {
    dsu[find(src)] = find(dst);
}

// 普通的并查集无法维护集合的传递关系
// 对于种类并查集，n 种关系代表 n 个并查集：
// 题干中已知只有三类动物，构成 A 吃 B，B 吃 C，C 吃 A 的环形食物链
// 因此我们需要同类集、猎物集、天敌集共 3 个并查集，表示维护三类动物的关系
// 对于 x > y，我们同时将 x 加入 y 的天敌集合，将 y 加入 x 的猎物集合，同时还要将 x 的天敌加入 y 猎物集合
// 对于 x = y，我们同时将 x 与 y 在同类集、猎物集、天敌集中分别进行合并
// 在进行合并操作时进行假话验证
void solve() {
    int n, k, ans = 0; cin >> n >> k;
    // 我们开三倍长度的并查集，用倍数关系来表示三个并查集
    dsu.resize(3*n+1); for(int i = 1; i <= 3*n; i++) dsu[i] = i;
    
    while(k--){
        int p, x, y; cin >> p >> x >> y;
        // 输入 > N 时直接为假
        if(x < 1 || x > n || y < 1 || y > n) {
            ans++; continue;
        }
        if(p == 1){
            // 真假性验证：如果两者已经存在捕食关系，则为假
            if(find(x) == find(y+n) || find(x+n) == find(y)) {
                ans++; continue;
            }
            // 三个集合分别进行合并
            unite(x,y); unite(x+n,y+n); unite(x+2*n,y+2*n);
        }
        else{
            // 真假性验证：如果两者相同 / 同类 / 已经有相反的捕食关系，则为假
            if(x == y || find(x) == find(y) || find(x) == find(y+n)){
                ans++; continue;
            }
            // 完善 A 吃 B，B 吃 C，C 吃 A 的环形食物链
            unite(x,y+2*n); unite(x+n,y); unite(x+2*n,y+n);
        }
    }
    cout << ans;
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