/* Title: P3956 [NOIP 2017 普及组] 棋盘
 *
 * From Luogu: https://www.luogu.com.cn/problem/P3956
 *
 * Record: https://www.luogu.com.cn/record/259002723
*/

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()	// sort(all(v), cmp);
#define pb push_back					// vector.pb(1);
#define INF 0x3f3f3f3f

// #define int long long

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;

/*
    从非魔法格 s 出发，在允许使用魔法的情况下，最多两步可以到达的所有地方
    代价是格子处的数字，加上与起点颜色不相等的情况下的 1 点额外代价

    +---+---+---+---+---+
    | x | x | 2 | x | x |
    +---+---+---+---+---+
    | x | 2 | 1 | 2 | x |
    +---+---+---+---+---+
    | 2 | 1 | s | 1 | 2 | <-- 以这里的 2 为例，这里考虑 2 的前提是其左侧的 1 没有上色
    +---+---+---+---+---+     （换言之，只有邻格无色时，才会考虑更远的 2 权值格子）
    | x | 2 | 1 | 2 | x |     （否则没必要在同一轮寻路下考虑更远的格子）
    +---+---+---+---+---+
    | x | x | 2 | x | x |
    +---+---+---+---+---+

    这里的内容可以和 Dijkstra 的松弛操作关联着看
*/

// 和 dis 相似的结构
struct Node{
    int dis;
    int x, y;
    int color;
    int magic;
};

struct Cmp {
    bool operator()(const Node& a, const Node& b) const {
        return a.dis > b.dis;
    }
};

// 便于四个方向寻路
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

// 类比为非负权值的最短路问题，考虑转化为 Dijkstra
void solve() {
    int m, n; cin >> m >> n;

    // -1 -> null, 0 -> red, 1 -> yellow
    vvi a(m, vi(m, -1));
    for(int i = 0; i < n; i++){
        int x, y, c; cin >> x >> y >> c;
        a[--x][--y] = c;
    }

    // Dijkstra 的最短路记录，新增了两个维度
    // color 指代颜色，magic 指代是否为施法格
    // 相当于在原 dis 的二位数组的基础上添加了状态信息，可以理解为 dp
    int dis[101][101][2][2]; 
    memset(dis, 0x3f, sizeof(dis)); // 全部初始化为 INF = 0x3f3f3f3f
    dis[0][0][a[0][0]][0] = 0;

    priority_queue<Node, vector<Node>, Cmp> pq;
    pq.push({0, 0, 0, a[0][0], 0});

    // 松弛操作循环
    while(!pq.empty()){
        Node cur = pq.top(); pq.pop();
        int d = cur.dis, x = cur.x, y = cur.y, c = cur.color, magic = cur.magic;
        if (d != dis[x][y][c][magic]) continue;

        // 四个相邻块寻路
        for(int i = 0; i < 4; i++){
            int X = x + dx[i];
            int Y = y + dy[i];
            if(X < 0 || X >= m || Y < 0 || Y >= m) continue;
            
            // 临近块有颜色
            if(a[X][Y] != -1){
                // dis[u] + edge.w < dis[edge.v]
                int new_d = d + ((c != a[X][Y]) ? 1 : 0);
                if(new_d < dis[X][Y][a[X][Y]][0]){
                    dis[X][Y][a[X][Y]][0] = new_d;
                    pq.push({new_d, X, Y, a[X][Y], 0});
                }
            }

            // 临近块没有颜色，需要 magic 看 2 权值方块
            else{
                // 不能重复 magic
                if (magic == 1) continue;
                // 两种颜色都试一遍
                for(int two = 0; two <= 1; two++){
                    int new_d = d + 2 + ((c != two) ? 1 : 0);
                    if(new_d < dis[X][Y][two][1]){
                        dis[X][Y][two][1] = new_d;
                        pq.push({new_d, X, Y, two, 1});
                    }
                }
            }
        }
    }

    // 对四个状态值取更小的
    int ans = min({INF, dis[m-1][m-1][0][0], dis[m-1][m-1][0][1], dis[m-1][m-1][1][0], dis[m-1][m-1][1][1]});
    cout << (ans == INF ? -1 : ans);
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

// 这题在某个题单里的标签是 DFS
// 但是 DFS 记忆化 + 剪枝可能不如 Dijkstra（