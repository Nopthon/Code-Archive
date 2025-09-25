/* Title: P1541 [NOIP 2010 提高组] 乌龟棋
 *
 * From Luogu: https://www.luogu.com.cn/problem/P1541
 *
 * Record: https://www.luogu.com.cn/record/236877667
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
    int n,m;
    cin >> n >> m;
    vi score(n), card(4+1 ,0);
    
    for(int& i : score) cin >> i;
    for(int i = 0; i < m; i++) {
        int t; cin >> t;
        card[t]++;
    }

    // 因为四种爬行卡片的个数都不超过 40，所以大胆设置四维 dp
    // dp[a][b][c][d] 表示已使用四种牌分别为 a,b,c,d 张时的最大分数
    int dp[41][41][41][41] = {{{{{score[0]}}}}};    // 包含对第一个元素的初始化
    for(int a = 0; a <= card[1]; a++)
        for(int b = 0; b <= card[2]; b++)
            for(int c = 0; c <= card[3]; c++)
                for(int d = 0; d <= card[4]; d++){
                    int to_add = score[a + 2*b + 3*c + 4*d];
                    // dp[a][b][c][d] 的上一步只可能是
                    // dp[a-1][b][c][d], ... , dp[a][b][c][d-1] 中的一种
                    // 四种情况取最大值即可，此为状态方程
                    if(a) dp[a][b][c][d] = max(dp[a][b][c][d], dp[a-1][b][c][d] + to_add);
                    if(b) dp[a][b][c][d] = max(dp[a][b][c][d], dp[a][b-1][c][d] + to_add);
                    if(c) dp[a][b][c][d] = max(dp[a][b][c][d], dp[a][b][c-1][d] + to_add);
                    if(d) dp[a][b][c][d] = max(dp[a][b][c][d], dp[a][b][c][d-1] + to_add);
                }
    cout << dp[card[1]][card[2]][card[3]][card[4]];
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