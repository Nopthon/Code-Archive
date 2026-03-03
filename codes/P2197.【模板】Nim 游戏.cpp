/* Title: P2197 【模板】Nim 游戏
 *
 * From Luogu: https://www.luogu.com.cn/problem/P2197
 *
 * Record: https://www.luogu.com.cn/record/259746182
*/

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()	// sort(all(v), cmp);
#define pb push_back					// vector.pb(1);

// #define int long long

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;

// 经典的 Nim 博弈
// 对于一个给定的初始局面，双方均执行最优解，其状态转移是有限且固定的，考虑先手要么必胜，要么必败
// 首先，我们需要递归式地总结状态转移的规律：
// 1. 某个状态不再存在后继，则为必败状态（对于 Nim 博弈，所有的递归终点就是“拿完了全部石子”）
// 2. 某个状态是必胜状态，当且仅当至少某个后继是必败状态（先手只要制造出该必败状态，就能让后手必败）
// 3. 某个状态是必败状态，当且仅当所有后继是必胜状态（先手无论怎么做，都会让后手进入必胜状态）
// - 现在我希望找到一个和当前局面相关的变量，编码为“必胜”和“必败”之后满足该性质
// 现在我们引入 Nim sum = 所有堆石子数量的异或和，其恰好满足上述的性质：
// 1. 没有石子的最终状态满足 Nim sum == 0
// 因此我们将 Nim sum == 0 编码为必败，Nim sum == 1 编码为必胜
// 2. 对于 Nim sum != 0，我们取 a_p，使得其他数字的异或结果 a_others < a_p（这是一定可以实现的）
// 此时 Nim sum = a_p XOR a_others，将 a_p 减小为 a_others，计算结果就为 0
// 也就是说 Nim sum != 0 一定存在 Nim sum == 0 的后继
// 3. 对于 Nim sum == 0，随意减小某一个数的值，一定会改变至少一个比特位的 1 的个数的奇偶性
// 也就是说 Nim sum == 0 的所有后继一定为 Nim sum != 0
// 综上，Nim sum 可以准确指示某初始状态是否先手必胜。进一步的可以关注 Sprague–Grundy 理论


void solve() {
    int n; cin >> n;
    int nim_sum = 0, tmp;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        nim_sum ^= tmp;
    }
    cout << (nim_sum == 0 ? "No\n" : "Yes\n");
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int t; 
    cin >> t;		// multi testcases
    // t = 1;			// single testcase
    
    while (t--){
        solve();
    }
    
    return 0;
}