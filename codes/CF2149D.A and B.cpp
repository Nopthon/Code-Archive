/* Title: CF2149D. A and B
 *
 * From Codeforces: https://codeforces.com/contest/2149/problem/D
 *
 * Translate from Luogu: https://www.luogu.com.cn/problem/CF2149D
 *
 * Record: https://codeforces.com/contest/2149/submission/340495275
 */

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()  // sort(all(v), cmp);
#define pb push_back                   // vector.pb(1);

// #define int long long

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;

int fun(vi pos) {
    int len = pos.size();
    int res = 0;
    if (pos.empty()) return 0;
    vi a(len);
    for (int i = 0; i < len; i++) {
        a[i] = pos[i] - i;
    }
    nth_element(a.begin(), a.begin() + len / 2, a.end());
    for (int i = 0; i < len; i++) {
        res += abs(pos[i] - (a[len / 2] + i));
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vi apos, bpos;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a')
            apos.pb(i);
        else
            bpos.pb(i);
    }

    cout << min(fun(apos), fun(bpos)) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;		// multi testcases
    // t = 1;			// single testcase

    while (t--) {
        solve();
    }

    return 0;
}