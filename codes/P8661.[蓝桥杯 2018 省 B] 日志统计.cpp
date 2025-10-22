/* Title: P8661 [蓝桥杯 2018 省 B] 日志统计
 *
 * From Luogu: https://www.luogu.com.cn/problem/P8661
 *
 * Record: https://www.luogu.com.cn/record/241943603
*/

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()	// sort(all(v), cmp);
#define pb push_back					// vector.pb(1);

// #define int long long

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;

typedef struct {
    int ts;
    int id;
} post;

bool cmp (post a, post b){
    return ( (a.id < b.id) || (a.id == b.id) && (a.ts < b.ts));
}

void solve() {
    int n, d, k; cin >>n>>d>>k;
    vector<post> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].ts >> a[i].id;
    }
    
    // 方便在多个 id 的数据中使用一个单调窗口
    sort(all(a), cmp);

    int l = 0, r = 0;
    int sum = 0;

    // 对于同一个 $id$ 的帖子，按照 $ts$ 大小排序构造滑动窗口，根据 $data[r].ts - data[l].ts$ 的大小伸缩窗口长度
    // 如果存在窗口元素 $\geq k$ 的时刻，那么这个帖子被选中
    // 对于多个 $id$ 的帖子，我们先按照 $id$ 对数据排序（对于同 $id$ 数据按照 $ts$ 大小排序）
    // 然后添加左右边界 id 值不同时的跳转逻辑，实现一个滑动窗口对所有 id 使用

    while (r < n){
        while (a[r].ts - a[l].ts < d && a[l].id == a[r].id){
            sum += 1;
            r++;
        }
        r--;
        if(sum >= k || a[l].id != a[r+1].id){
            if (sum >= k) cout << a[l].id << "\n";
            r++; l = r; sum = 0;
        }
        while (a[r].ts - a[l].ts >= d && l < r){
            sum -= 1;
            l++;
        }
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
