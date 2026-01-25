/* Title: CF2131E. Adjacent XOR
 *
 * From Codeforces: https://codeforces.com/contest/2131/problem/E
 *
 * Translate from Luogu: https://www.luogu.com.cn/problem/CF2131E
 *
 * Record: https://codeforces.com/contest/2131/submission/341027607
 */

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()  // sort(all(v), cmp);
#define pb push_back                   // vector.pb(1);

// #define int long long

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<int> xnor(n, 0);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;
    if (a[n - 1] != b[n - 1]) {
        cout << "No\n";
        return;
    }
    bool check = true;
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] != b[i]) {
            if (((a[i] ^ a[i + 1]) != b[i]) && ((a[i] ^ b[i + 1]) != b[i])) {
                check = false;
                break;
            }
        }
        else check = true;
    }
    cout << (check ? "Yes\n" : "No\n");
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;  // multi testcases
    // t = 1;			// single testcase

    while (t--) {
        solve();
    }

    return 0;
}