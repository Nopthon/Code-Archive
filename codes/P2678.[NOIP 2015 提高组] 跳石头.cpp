/* Title: P2678 [NOIP 2015 提高组] 跳石头
 *
 * From Luogu: https://www.luogu.com.cn/problem/P2678
 *
 * Record: https://www.luogu.com.cn/record/259538783
*/

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()	// sort(all(v), cmp);
#define pb push_back					// vector.pb(1);

// #define int long long

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;

// 发现无法通过某种贪心策略实现 O(n) 下的最优搬石头策略
// 考虑二分答案 d，将题目转化为：是否存在最多 m 次删点，使得 dis_min >= d
// 此时贪心策略是明确的，只要遇到 dis < d 的，就搬走右侧的石头（结尾特判）
// 一轮遍历能够实现 all dis >= d，据此进行答案二分
// O(n · logn)
void solve() {
    int len, n, m; cin >> len >> n >> m;
    // d[] 记录的是 n+1 段相邻距离
    vi d(n+1); d[n] = len;
    for(int i = 0; i < n; i++) cin >> d[i];
    for(int i = n; i >= 1; i--) d[i] -= d[i-1];
    
    int l = 1, r = len, ans = 1;
    while (l <= r){
        int mid = l +((r-l) >> 1);
        int cnt = 0, gap = d[0];
        // 只要遇到 dis < mid，就搬走右侧的石头，累加 gap 值直到超过 >= mid
        for(int i = 1; i <= n; i++){
            if(gap < mid){
                cnt++; gap += d[i];
            }
            else gap = d[i];
        }

        // 因为终点石头不可搬，因此需要特判，否则 100 Unaccepted
        // 这里的 cnt++ 指的是和左侧的区间合并（而不是搬走不可搬的终点石头）
        // 经历之前的搬石头过程后，可以保证只需要移除第 n 个石头，就可以使 gap >= mid
        if(gap < mid) cnt++;

        if(cnt <= m){
            ans = mid;
            l = mid + 1;
        } else r = mid - 1; 
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