/* Title: P3375 【模板】KMP
 *
 * From Luogu: https://www.luogu.com.cn/problem/P3375
 *
 * Record1: https://www.luogu.com.cn/record/238420170 (normal)
 * 
 * Record2: https://www.luogu.com.cn/record/239653005 (combined)
 */

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()  // sort(all(v), cmp);
#define pb push_back                   // vector.pb(1);

// #define int long long

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;

// Subfunc: 计算前缀函数
void calc_pi(vi& pi, const string& s, int& n) {
    /* 这里是 O(n^3) 复杂度的暴力匹配方法，直观但低效
    for (int i = 1; i < n; i++)
        for (int j = i; j >= 0; j--)
            if (s.substr(0, j) == s.substr(i - j + 1, j)) {
                pi[i] = j;
                break;
            }
    */
    // 已经初始化 pi[0] = 0
    for (int i = 1; i < n; i++) {
        // j 表示当前匹配的前缀长i
        // 因为我们初始状态下是尝试 “能不能从上一次匹配接续”
        // 所以初始化 j = pi[i-1] 而不是 j = 0 （两者都可以，前者常数更优）
        int j = pi[i - 1];
        // 当字符不匹配时，回退到前一个可能匹配的位置
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];  // 利用已计算的前缀函数值进行回退
                            // 可以参考题解最下面的【Example 1】
        // 直到当前字符匹配，在上一次成功匹配的基础上向后插入（j++）
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
}

void solve() {
    // 题目大意：
    // 求出 s2 在 s1 中所有出现的位置
    // 以及求出 s2 的前缀函数 pi
    string s1, s2;
    cin >> s1 >> s2;
    int len1 = s1.size(), len2 = s2.size();

    // Step1: 求出“前缀函数 pi”
    // pi[i] 表示 s[0...i] 的最长的相等的真前缀与真后缀的长度
    vi pi(len2, 0);
    calc_pi(pi, s2, len2);

    // Step2: 根据前缀函数求出所有的匹配位置
    // 在暴力的算法中，待匹配串指针 i 为了不遗漏匹配会反复回退
    // 如果想实现 i 的不回退，就要让 j 在失配时不从头开始匹配
    // 前缀函数就解决了 “j 从哪里开始继续匹配” 的问题【Example 2】
    // 时间复杂度由 O(mn) 缩短至 O(m+n)，O(m) 由 Step1 贡献
    for (int i = 0, j = 0; i < len1; i++) {
        while (j > 0 && s1[i] != s2[j]) j = pi[j - 1];
        if (s1[i] == s2[j]) j++;
        if (j == len2) {
            cout << i - len2 + 2 << "\n";
            j = pi[j - 1];
        }
    }

    // 输出第一问要求的前缀函数
    for (int& x : pi) cout << x << " ";
}

void combined_solve() {
    // 还有一种将两个字符串拼接在一起的写法
    // 时间复杂度在常数上其实没有优势
    // 在扩展 KMP 算法中更加常用
    string s1, s2;
    cin >> s1 >> s2;
    int len1 = s1.size(), len2 = s2.size();
    
    string combined = s2 + "#" + s1;
    int combined_len = combined.size();
    
    vi pi(combined_len, 0);
    calc_pi(pi, combined, combined_len);

    for (int i = len2 + 1; i < combined_len; i++) {
        if (pi[i] == len2) {
            cout << (i - 2*len2 + 1) << "\n";
        }
    }

    // 输出 s2 的前缀函数（只输出到 len2 的长度）
    for (int i = 0; i < len2; i++)
        cout << pi[i] << " ";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    // cin >> t;		// multi testcases
    t = 1;  // single testcase

    while (t--) {
        combined_solve();
    }

    return 0;
}

/* Example 1: 生成 [a, a, b, a, a, b, a, a, a] 的前缀函数
 * a a b a a b a a a
 * 0 1 0 1 2 3 4 ? ?    // pi[7] pi[8] 待计算
 * 下一步计算：因为 s[i] == s[j] 成立，所以 pi[7] = pi[6] + 1 = 5
 * 下一步计算：因为 s[i] == s[j] 不成立，所以回退到 j = pi[4] = 2
 * 此时 s[i] == s[j] 依旧不成立，回退到 j = pi[1] = 1
 * 此时 s[i] == s[j] 成立，得到 pi[8] = j + 1 = 2
 */

/* Example 2: 寻找 ABABC in ABABABC：
 * ABABABC        待匹配串，已知模式串 pi[5] = {0,0,1,2,0}
 * ABABC          第一次匹配，在 s2[3] “之后”失配
 * ->ABABC        因此下一次比较时就可以跳过前 pi[3] 个字符，从 s2[3] 开始与
 * s1[i] 比较 （在这个例子中，因为 s2[3] 对应的 "ABAB"
 * 的前两个字母与后两个字母相同，因此实现了跳过）
 */