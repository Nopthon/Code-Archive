/* Title: CF609D Gadgets for dollars and pounds
 *
 * From Codeforces: https://codeforces.com/contest/609/problem/D
 *
 * Translate from Luogu: https://www.luogu.com.cn/problem/CF609D
 *
 * Record: https://codeforces.com/contest/609/submission/360445387
*/

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()	// sort(all(v), cmp);
#define pb push_back					// vector.pb(1);

// #define int long long

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;

// 买东西有两个制约因素：剩余钱币数、时间限制
// 考虑直接进行贪心不够现实，并且最短天数满足决策单调性等，考虑二分答案
// 对于指定的 day，对钱币数贪心处理，判断 min_cost 是否超过 s
// 由于还需要维护第 d 天买第 g 种物品，因此大多数数组都额外存储了一些内容（恼）
void solve() {
    int n, m, k, s; 
    cin >> n >> m >> k >> s;

    // dollar[i] = {最小汇率, 对应天数}
    vector<pair<int,int>> dollar(n), pound(n);
    vector<pair<int,int>> goods(m); // {type, price}

    cin >> dollar[0].first;
    dollar[0].second = 0;
    for(int i = 1; i < n; i++){
        cin >> dollar[i].first;
        if(dollar[i].first > dollar[i-1].first)
            dollar[i] = dollar[i-1];
        else
            dollar[i].second = i;
    }

    cin >> pound[0].first;
    pound[0].second = 0;
    for(int i = 1; i < n; i++){
        cin >> pound[i].first;
        if(pound[i].first > pound[i-1].first)
            pound[i] = pound[i-1];
        else
            pound[i].second = i;
    }

    // goods[i] = {type, price}
    for(int i = 0; i < m; i++){
        cin >> goods[i].first >> goods[i].second;
    }

    int l = 0, r = n-1, ans = -1;
    vector<pair<int,int>> ans_buy; // {good_id, day}

    while(l <= r){
        int mid = (l + r) / 2;
        auto [dRate, dDay] = dollar[mid];
        auto [pRate, pDay] = pound[mid];

        vector<pair<ll,int>> prices; // {cost, index}
        prices.reserve(m);

        for(int i = 0; i < m; i++){
            if(goods[i].first == 1)
                prices.pb({1LL * dRate * goods[i].second, i});
            else
                prices.pb({1LL * pRate * goods[i].second, i});
        }

        partial_sort(prices.begin(), prices.begin() + k, prices.end());

        ll cost = 0;
        vector<pair<int,int>> cur;
        for(int i = 0; i < k; i++){
            cost += prices[i].first;
            int idx = prices[i].second;
            if(goods[idx].first == 1)
                cur.pb({idx + 1, dDay + 1}); // 0-index 转成 1-index
            else
                cur.pb({idx + 1, pDay + 1});
        }

        if(cost > s){
            l = mid + 1;
        } else {
            ans = mid + 1; // 0-index 转成 1-index
            ans_buy = cur;
            r = mid - 1;
        }
    }

    cout << ans << "\n";
    if(ans != -1){
        for(auto &x : ans_buy){
            cout << x.first << " " << x.second << "\n";
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