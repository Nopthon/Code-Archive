/* Title: A+B Problem
 *
 * From Luogu: https://www.luogu.com.cn/problem/P1001
*/

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()	// sort(all(v), cmp);
#define pb push_back					// vector.pb(1);

// #define int long long

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int t; 
    // cin >> t;		// multi testcases
    t = 1;			// single testcases
    
    while (t--){
        int a, b;
        cin >> a >> b;
        cout << a + b;
    }
    
    return 0;
}