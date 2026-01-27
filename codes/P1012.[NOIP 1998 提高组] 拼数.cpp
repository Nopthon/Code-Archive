/* Title: P1012 [NOIP 1998 提高组] 拼数
 *
 * From Luogu: https://www.luogu.com.cn/problem/P1012
 *
 * Record: https://www.luogu.com.cn/record/
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
    int n; cin >> n;
    vector<string> nums(n);
    for(string& x : nums) cin >> x;

    sort(all(nums), [](const string &a,const string &b){
        return a + b > b + a;
    });

    for(string& x : nums) cout << x;
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