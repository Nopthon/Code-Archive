/* Title: P3375 【模板】KMP
 *
 * From Luogu: https://www.luogu.com.cn/problem/P3375
 *
 * Record: https://www.luogu.com.cn/record/
 */

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()  // sort(all(v), cmp);
#define pb push_back                   // vector.pb(1);

// #define int long long

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;

void calc_pi(vi& pi, string& s2, int& len2){
    for (int i = 1; i < len2; i++) {
        int j = pi[i - 1];
        while (j > 0 && s2[i] != s2[j])
            j = pi[j - 1];
        if (s2[i] == s2[j]) j++;
        pi[i] = j;
    }
}


void solve() {
    // 题目大意：
    // 求出 s2 在 s1 中所有出现的位置
    // 以及求出 s2 的前缀函数 pi （pi[i] 表示 s[0...i] 的最长的相等的真前缀与真后缀的长度）
    string s1, s2; cin >> s1 >> s2;
    int len1 = s1.size(), len2 = s2.size();

    // Step1: 求出前缀函数
    vi pi(len2, 0);
    calc_pi(pi, s2, len2);

    // Step2: 根据前缀函数求出所有的匹配位置
    for (int i = 0, j = 0; i < len1; i++) {
        while (j > 0 && s1[i] != s2[j])
            j = pi[j - 1];
        if (s1[i] == s2[j]) j++;
        if (j == len2) {
            cout << i - len2 + 2 << "\n";
            j = pi[j - 1];
        }
    }

    // 输出第二问要求的前缀函数
    for (int &x : pi) cout << x << " ";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    // cin >> t;		// multi testcases
    t = 1;			// single testcase

    while (t--) {
        solve();
    }

    return 0;
}