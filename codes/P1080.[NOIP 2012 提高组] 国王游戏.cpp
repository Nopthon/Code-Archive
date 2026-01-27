/* Title: P1080 [NOIP 2012 提高组] 国王游戏
 *
 * From Luogu: https://www.luogu.com.cn/problem/P1080
 *
 * Record: https://www.luogu.com.cn/record/259189394
*/

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()	// sort(all(v), cmp);
#define pb push_back					// vector.pb(1);

// #define int long long

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;

// for 压位高精度
const int WIDTH = 4;
const int BASE = 10000;	

struct node{
	int left;
	int right;
};

// 高精度数打印
void Print(const vi& num)
{
	if (num.empty())
    {
        cout << "0" << endl; return;
    }
    cout << num.back();
    for (int i = num.size() - 2; i >= 0; --i)
        cout << setw(WIDTH) << setfill('0') << num[i];
}

// 高精度 × 低精度
vi Mul_l(const vi& a, int x)
{
    vi res;
    long long carry = 0;
    for (int i = 0; i < a.size() || carry; ++i)
    {
        if (i < a.size()) carry += (long long)a[i] * x;
        res.push_back(carry % BASE);
        carry /= BASE;
    }
    while (res.size() > 1 && res.back() == 0) res.pop_back();
    return res;
}

// 高精度 ÷ 低精度
vi Div_l(const vi& a, int x) {
    vi quotient;
    long long remainder = 0;

    for (auto it = a.rbegin(); it != a.rend(); ++it)
	{
        long long temp = remainder * BASE + *it;
        quotient.push_back(temp / x);
        remainder = temp % x;
    }

    reverse(quotient.begin(), quotient.end());

    while (!quotient.empty() && quotient.back() == 0) quotient.pop_back();

    return quotient.empty() ? vi{0} : quotient;
}

// 高精度比较大小
vector<int> findMax(const vector<int>& a, const vector<int>& b)
{
	if (a.size() > b.size()) return a;
		else if (a.size() < b.size()) return b;
	
	for (int i = a.size() - 1; i >= 0; --i)
	{
		if (a[i] > b[i]) return a;
		else if (a[i] < b[i]) return b;
	}
	
	return a;
}


// 核心是邻项交换法（贪心）
// 邻项交换的另一个更经典的用例是 P1012 拼数（给定一组数字，按某种顺序拼接成一个最大的数）
// 两道题都是证明难度 > 代码实现
// 这题最粪的地方在于计算答案时需要高精度
void solve() {
	int n; cin >> n;
	vector<node> a(n+1);
	for(node& x : a) cin >> x.left >> x.right;

	// 注意到我们需要调整 a[1] ~ a[n] 使得满足某种最值的解
	// 尝试邻项交换法，本质上是一种贪心
	// 结尾提供了贪心正确性的证明
	sort(a.begin()+1, a.end(), [](const node &a, const node &b){
		return a.left * a.right < b.right * b.left;
	});

	// 高精度计算过程
	vi plus = {a[0].left}, ans = {0};
	for(int i = 1; i <= n; i++){
		ans = findMax(ans, Div_l(plus, a[i].right));
		plus = Mul_l(plus, a[i].left);
	}

	Print(ans);
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

// 对于贪心算法正确性的证明
// 首先考虑一定有某一种最优解排列 a_best[]（不是唯一的，但是一定存在）
// 考虑两个相邻元素（大臣） a 与 b，容易得到交换两者的位置只会影响这两者的金币数
// 由此进一步得到，一定可以通过某种邻项交换的规则达成最优解
// 现在考虑 la, lb, ra, rb 这四个变量，以及这两个人前面所有人的左手乘积为 S
// 交换前这两人中获得的金币数最多为 max(S/ra, S*la/rb)，交换后为 max(S/rb, S*lb/ra)
// 我们考虑 max(S/ra, S*la/rb) < max(S/rb, S*lb/ra)，也就是不执行交换更优

/* 接下来对式子进行化简：max(S/ra, S*la/rb) < max(S/rb, S*lb/ra)
 * 等式两边同乘 (ra*rb/S)：max(rb, la*ra) < max(ra, lb*rb)
 * 考虑 la*ra > lb*rb，此时 la*ra > lb*rb >= rb，因此 max(rb, la*ra) = la*ra
 * 不难发现 la*ra < max(ra, lb*rb) 是矛盾的，因为 la*ra > ra 且 la*ra > lb*rb
 * 因此我们发现 la*ra > lb*rb 时，“不执行交换更优” 的式子不成立
 */

// 因此 la*ra > lb*rb 时，交换会得到更优解，也就是令 l*r 更小的元素放在前面
// 因此我们得到了按照 l*r 升序的结论

// 我写这题的时候这题还是个绿，怎么升蓝了