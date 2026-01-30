/* Title: P3373 【模板】线段树 2
 *
 * From Luogu: https://www.luogu.com.cn/problem/P3373
 *
 * Record: https://www.luogu.com.cn/record/259706709
*/

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()	// sort(all(v), cmp);
#define pb push_back					// vector.pb(1);

// #define int long long

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;

/* 在上一题的基础上，添加了区间乘的操作（顺便还得给区间和取个模）
 * 因此懒更新也需要分别维护乘法和加法的 lazy 标签
 * x <- x * lazy_mul[node] + lazy_add[node]
 */
vector<ll> tree, lazy_add, lazy_mul;
int MOD = 1;

void Build(int node, int l, int r){
	if(l == r){
		cin >> tree[node];
		return;
	}

	int mid = l + (r-l) / 2;
	int left = node << 1;
	Build(left, l, mid);
	Build(left + 1, mid + 1, r);
    //
	tree[node] = (tree[left] + tree[left+1]) % MOD;
}

void build(int n){
    tree.resize(4*n+5);
    lazy_add.resize(4*n+5, 0);  // 加法的单位元是 0
    lazy_mul.resize(4*n+5, 1);  // 乘法的单位元是 1
    Build(1, 1, n);
}

/* pushDown 需要同时关注加法和乘法的懒更新传递
 */
void pushDown(int node, int l, int r){
    if(l == r || (lazy_add[node] == 0 && lazy_mul[node] == 1) )return;
    int mid = l + (r-l) / 2;
    int left = node << 1, right = left + 1;

    // 先乘法，后加法
    // 如果不明白这里为何这样计算，去看 UpdateMul 函数
    tree[left] = (tree[left] * lazy_mul[node] % MOD + lazy_add[node] * (mid - l + 1) % MOD) % MOD;
    tree[right] = (tree[right] * lazy_mul[node] % MOD + lazy_add[node] * (r - mid) % MOD) % MOD;

    // 更新左右子节点的 lazy 标签
    lazy_mul[left] = (lazy_mul[left] * lazy_mul[node]) % MOD;
    lazy_add[left] = (lazy_add[left] * lazy_mul[node] % MOD + lazy_add[node] % MOD) % MOD;
    
    lazy_mul[right] = (lazy_mul[right] * lazy_mul[node]) % MOD;
    lazy_add[right] = (lazy_add[right] * lazy_mul[node] % MOD + lazy_add[node] % MOD) % MOD;

    lazy_add[node] = 0;
    lazy_mul[node] = 1;
}

ll Query(int node, int l, int r, int ql, int qr){
	if(ql <= l && r <= qr){
		return tree[node];
	}

    pushDown(node, l, r);

	int mid = l + (r-l) / 2;
	int left = node << 1;
    //
	ll res = 0;
	if(ql <= mid){
		res += Query(left, l, mid, ql, qr);
	} 
	if(qr > mid){
		res += Query(left+1, mid+1, r, ql, qr);
	}
	return res;
}

ll query(int l, int r, int n){
    return Query(1, 1, n, l, r);
}

/* 区间加法保持不变（除了取模），为了命名整洁修改了函数名
*/
void UpdateAdd(int node, int l, int r, int ql, int qr, ll val) {
    if (ql <= l && r <= qr) {
        tree[node] = (tree[node] + val % MOD * (r - l + 1)) % MOD;
        lazy_add[node] = (lazy_add[node] + val) % MOD;
        return;
    }
    
    pushDown(node, l, r);
    
    int mid = (l + r) >> 1;
    int left = node << 1;
    
    if (ql <= mid) {
        UpdateAdd(left, l, mid, ql, qr, val);
    }
    if (qr > mid) {
        UpdateAdd(left + 1, mid + 1, r, ql, qr, val);
    }
    //
    tree[node] = (tree[left] + tree[left + 1]) % MOD;
}

void updateAdd(int l, int r, ll val, int n) {
    UpdateAdd(1, 1, n, l, r, val);
}

/* 添加了区间乘积的维护
*/
void UpdateMul(int node, int l, int r, int ql, int qr, ll val) {
    if (ql <= l && r <= qr) {
        // 注意：懒标记维护的真实值是 x * lazy_mul[node] + lazy_add[node]
        // 而加法和乘法运算顺序不同，如果直接修改某一个 lazy 标签，会丢失运算顺序的信息
        // 现在我们考虑对 (x * lazy_mul + lazy_add) * val
        // 展开后我们发现 lazy_mul 和 lazy_add 都被乘上了 val
        // 对应下面的代码
        val %= MOD;
        tree[node] = (tree[node] * val) % MOD;
        lazy_mul[node] = (lazy_mul[node] * val) % MOD;
        lazy_add[node] = (lazy_add[node] * val) % MOD;
        return;
    }
    
    pushDown(node, l, r);
    
    int mid = (l + r) >> 1;
    int left = node << 1;
    
    if (ql <= mid) {
        UpdateMul(left, l, mid, ql, qr, val);
    }
    if (qr > mid) {
        UpdateMul(left + 1, mid + 1, r, ql, qr, val);
    }
    //
    tree[node] = (tree[left] + tree[left + 1]) % MOD;
}

void updateMul(int l, int r, ll val, int n) {
    UpdateMul(1, 1, n, l, r, val);
}

void solve() {
    int n, q; cin >> n >> q >> MOD;

    build(n);

    while(q--){
        // 注意这里 k 要开 ll
        int t, x, y; ll k; cin >> t;
        switch(t){
        case 1:
            cin >> x >> y >> k;
            updateMul(x, y, k, n);
            break;
        case 2:
            cin >> x >> y >> k;
            updateAdd(x, y, k, n);
            break;
        case 3:
            cin >> x >> y;
            cout << query(x, y, n) % MOD << "\n";
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