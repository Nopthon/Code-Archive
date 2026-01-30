/* Title: P3372 【模板】线段树 1
 *
 * From Luogu: https://www.luogu.com.cn/problem/P3372
 *
 * Record: https://www.luogu.com.cn/record/259642612
 */

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()	// sort(all(v), cmp);
#define pb push_back					// vector.pb(1);

// #define int long long

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;

/* 线段树的核心思想类似于二叉搜索树的思想
 * 用一棵完全二叉树，把数组区间不断二分，每个节点维护一个区间的信息
 * 这棵二叉树的 n 个叶子节点存储了原数组 a[n] 的内容
 * 然后我们向上完善二叉树，满足非叶节点记录的区间 = 左右子节点区间的并
 * 也就是说，非叶节点记录了原数组 a[n] 的一些区间信息，和原 a[n] 一并参与维护
 * 这个“区间信息”可以是求和，最大值/最小值，只要信息满足结合律即可：
 * INFO(node) = INFO(INFO(left), INFO(right))，比如 INFO = max / sum / ...
 * 这是线段树的基础
  */

/* 定义两个数组
 * tree 数组以堆存储的形式存储线段树
 * lazy 数组结构与 tree 相同，作用是在进行区间修改操作时，只进行预标记，不直接执行
 * 用于降低时间复杂度
 */
vector<ll> tree, lazy;

/* 构建线段树
 * 初始化树的大小至少为 4n
 * 然后采用后序遍历的思路自底向上构建整棵树
 */
void Build(int node, int l, int r){
	if(l == r){ // 到达叶节点，填入原数组的值
		cin >> tree[node];
		return;
	}

	int mid = l + (r-l) / 2;
	int left = node << 1;
	Build(left, l, mid);    // 左子树
	Build(left + 1, mid + 1, r);    // 右子树
    // 这里进行自底向上的 INFO 计算，对于本题 INFO = sum
    // 之后所有表示 INFO 计算的部分会在代码前面用单独的 //// 做标记，方便修改维护的信息
	tree[node] = tree[left] + tree[left+1];
}

// 封装
void build(int n){
    tree.resize(4*n+5);
    lazy.resize(4*n+5, 0);
    Build(1, 1, n);
}

/* 我们先讲解 lazy 的具体作用：
 * 对于朴素的区间加和操作，我们需要将所有 ⊆ [a, b] 的节点（包括子树）都进行更新
 * 而对于 lazy[node] += x，我们只记录 “node 代表的区间中每个元素被加过 x”，但是不会立刻传递信息到子区间
 * （从承载的信息来说：lazy[node] += x，对应 tree[node] 的子树的延迟更新）
 * 下面的 pushDown 函数用于将信息下传到子区间（只下传一次，不会一次下传到叶节点）
 * 只要在之后需要访问 tree[node] 的子树，就需要调用一次 pushDown，把懒标记转换为实际更新
 * 
 * 建议和 updateRange 一并看，这样你就知道 lazy[node] 不会影响 tree[node]，只会影响 tree[node] 的子树
 */

void pushDown(int node, int l, int r){
    // 如果是叶节点 or 没有 lazy 标记，就不用再向下更新了
    if(l == r || lazy[node] == 0) return;
    int mid = l + (r-l) / 2;
    int left = node << 1, right = left + 1;

    // tree[left]  += lazy[node] * 左区间长度;
    // 右区间同理
    tree[left] += lazy[node] * (mid - l + 1);
    tree[right] += lazy[node] * (r - mid);

    // 将 lazy 标签下放到左右子树
    lazy[left] += lazy[node];
    lazy[right] += lazy[node];

    // 原节点的 lazy 标签清空
    lazy[node] = 0;
}

/* 对区间 [l, r] 进行查询操作
 * 在实际的递归实现中，[l, r] 表示递归进行的区间，[ql, qr] 表示最初需要查询的区间
 * 具体的实现逻辑参考代码内注释
 */
ll Query(int node, int l, int r, int ql, int qr){
    // 如果 [l, r] ⊆ [ql, qr]，那么直接取出当前节点的值
	if(ql <= l && r <= qr){
		return tree[node];
	}

    // 否则区间部分覆盖，一定会涉及到左右子区间的递归查询
    // 在此之前必须将懒标记进行一轮向下的更新
    pushDown(node, l, r);

    // 二分向子树查询，结果为左右子树的结果和
	int mid = l + (r-l) / 2;
	int left = node << 1;
    ////
	ll res = 0;     // 如果是维护 min 的话，这里初始化 LLONG_MAX（其他同理）
	if(ql <= mid){  // 如果包含左子树的区间
		res += Query(left, l, mid, ql, qr);
	} 
	if(qr > mid){   // 如果包含右子树的区间
		res += Query(left+1, mid+1, r, ql, qr);
	}
    // 回溯累加结果
	return res;
}

// 封装

ll query(int l, int r, int n){
    return Query(1, 1, n, l, r);
}

/* 对区间 [l, r] 进行区间更新操作
 * 在实际的递归实现中，[l, r] 表示递归进行的区间，[ql, qr] 表示最初需要查询的区间
 * 具体的实现逻辑参考代码内注释
 */
void UpdateRange(int node, int l, int r, int ql, int qr, ll val) {
    // 如果 [l, r] ⊆ [ql, qr]，那么直接懒更新当前节点的值
    if (ql <= l && r <= qr) {
        // 注意当前节点是实时更新的，子树采用 lazy 懒更新
        tree[node] += val * (r - l + 1);    // val × length
        lazy[node] += val;
        return;
    }
    
    // 否则区间部分覆盖，一定会涉及到左右子区间的递归查询
    // 在此之前必须将懒标记进行一轮向下的更新
    pushDown(node, l, r);
    
    // 二分向子树更新，最终 tree[node] 为左右子树的结果和
    int mid = (l + r) >> 1;
    int left = node << 1;
    
    if (ql <= mid) {  // 如果包含左子树的区间
        UpdateRange(left, l, mid, ql, qr, val);
    }
    if (qr > mid) {   // 如果包含右子树的区间
        UpdateRange(left + 1, mid + 1, r, ql, qr, val);
    }
    ////
    tree[node] = tree[left] + tree[left + 1];
}

void updateRange(int l, int r, ll val, int n) {
    UpdateRange(1, 1, n, l, r, val);
}

void solve() {
    int n, m; cin >> n >> m;

    build(n);

    while(m--){
        // 注意这里 k 要开 ll
        int t, x, y; ll k; cin >> t;
        switch(t){
        case 1:
            cin >> x >> y >> k;
            updateRange(x, y, k, n);
            break;
        case 2:
            cin >> x >> y;
            cout << query(x, y, n) << "\n";
            break;
        default: break;
        }
    }
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