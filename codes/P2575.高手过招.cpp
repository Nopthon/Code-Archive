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

// 考虑游戏结束的条件为：所有石子到达第 0 阶
// 我们现在将所有的石子仅仅分为三个台阶：奇数阶 + 偶数阶 + 零台阶
// - 从偶数阶拿取任意个数的石子只能放到奇数阶，后手可以直接将这些石子放回偶数阶或零台阶
// -- 如果这不是台阶 1 的石子，那么上述操作无实际作用，石子又回到偶数阶
// -- 如果这是台阶 1 的石子，并且只剩下这些石子了，那么后手最终一定可以通过将这些石子从奇数阶移到零台阶获胜
// 因此我们发现，移动偶数阶的石子一定不会改变某一方的必胜局面
// 该 Nim 游戏的先后手获胜只与奇数阶石子总个数有关
// 也就是说阶梯 Nim 游戏完全是对所有奇数台阶的石子堆的经典 Nim 游戏（忽略偶数石子堆）
// 因此 Nim_sum = 所有奇数阶上棋子个数的异或和

// 接下来考虑这一题，每个棋子可以跳到右侧最近的空格中
// eg: [X] [x] [x] [] [x] [] [x] => [] [x] [x] [X] [x] [] [x]
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