/* Title: P2575 高手过招
 *
 * From Luogu: https://www.luogu.com.cn/problem/P2575
 *
 * Record: https://www.luogu.com.cn/record/259779766
*/

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()	// sort(all(v), cmp);
#define pb push_back					// vector.pb(1);

// #define int long long

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;

// 经典 Nim 的规则中，每个石头经过一次操作就会被移除
// 现在引入阶梯 Nim，规则是：有一个阶梯，编号为 1,2,...,N，每个阶梯上放若干石子
// 每次可以选择第 k 阶的若干石子，移动到第 k-1 阶（移动到第 0 阶即移出阶梯）
// 我们发现，对于任意偶数阶上的棋子，只能移动到对应的奇数阶中，而不能一次性被拿走
// 换句话说，对偶数阶上石子的任意操作，都可以由后手进行下一步处理
// 而奇数阶上的石子最终都会通过 1 -> 0 的方式被移走，使得总石子数有实质性减少
// 总结一下就是，只有对奇数阶上的棋子进行操作，才能“改变局面”；
// 对偶数阶的操作可以在下一步由后手任意操纵（对于后手，这部分棋子现在在奇数阶上了）
// 总结：Nim_sum = 所有奇数阶上棋子个数的异或和

// 接下来考虑这一题，每个棋子可以跳到右侧最近的空格中
// eg: [x] [x] [x] [] [x] [] [x] => [] [x] [x] [x] [x] [] [x]
// 等价为 [3] [1] [1] => [0] [4] [1]
// 发现对单个棋子的右移操作等价为对该棋子和右边相邻的棋子串共同右移一位，可以类比为阶梯 Nim
// 我们可以将初始态下的无棋子格子当作阶梯分界线，将奇数格上的棋子数异或得到 Nim_sum

void solve() {
    int n; cin >> n;
    int nim_sum = 0;
    bool line[21] = {0};

    while(n--){
        fill(line, line + 21, false);
        int m; cin >> m;
        for(int i = 1; i <= m; i++){
            int p; cin >> p;
            line[p] = true;
        }
        int step = 0;
        for(int p = 20; p >= 1;){
            if(!line[p]) {
                // 每个空白格子都表示一个台阶
                step++;
                p--;
            }
            else{
                int sum = 0;
                while (p >= 1 && line[p]){
                    // 连在一起的棋子串都在一个台阶上
                    sum++; p--;
                }
                if(step & 1) nim_sum ^= sum;
            }
        }
    }

    cout << (nim_sum == 0 ? "NO\n" : "YES\n");
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