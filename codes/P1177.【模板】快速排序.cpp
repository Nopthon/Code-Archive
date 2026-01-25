/* Title: P1177 【模板】快速排序
 *
 * From Luogu: https://www.luogu.com.cn/problem/P1177
 *
 * Record: https://www.luogu.com.cn/record/258862498
 */

#include <bits/stdc++.h>

// #define int long long

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;

// 对每个分区的的分区操作（小于|等于|大于 pivot 的三路排序）
// RandomIt 表明容器的迭代器必须支持随机访问；
// Compare 使得排序函数可以是函数指针、函数对象、lambda表达式
template <typename RandomIt, typename Compare>
pair<RandomIt, RandomIt> Partition(RandomIt first, RandomIt last, Compare comp) {
    // 三数取中法选择 pivot
    auto mid = first + (last - first) / 2;
    if (comp(*mid, *first)) iter_swap(first, mid);
    if (comp(*(last-1), *first)) iter_swap(first, last-1);
    if (comp(*(last-1), *mid)) iter_swap(mid, last-1);

    iter_swap(mid, prev(last));  // pivot放到最后
	auto pivot_val = *(prev(last));	// 保存 pivot 值
    
    auto lt = first;      // lt: 小于区域的边界（迭代器）
    auto i = first;       // i: 当前的遍历指针（迭代器）
    auto gt = prev(prev(last)); // gt: 大于区域的边界（迭代器）
    
    while (i <= gt) {
        if (comp(*i, pivot_val)) {
            // 当前元素小于pivot，放到左侧
            iter_swap(lt++, i++);
        } else if (comp(pivot_val, *i)) {
            // 当前元素大于pivot，放到右侧
            iter_swap(i, gt--);
            // 不递增i，因为 i 指向的新元素尚未check
        } else {
            // 当前元素等于pivot，留在中间
            ++i;
        }
    }
    
    // 将pivot从最后位置放到等于区域的末尾
    iter_swap(i, prev(last));
    
    // 返回等于区域的边界 [lt, i+1)
    return {lt, next(i)};
}

// 
template <typename RandomIt, typename Compare>
void quick_sort(RandomIt first, RandomIt last, Compare comp) {

    if (distance(first, last) <= 1) {
        return;
    }

    // 选择pivot并进行分区
    auto pivot_iter = Partition(first, last, comp);

    // 递归排序左右两部分
    quick_sort(first, pivot_iter.first, comp);
    quick_sort(pivot_iter.second, last, comp);
}

// 主排序函数（类似STL的sort接口）
template <typename RandomIt, typename Compare = less<>>
void Sort(RandomIt first, RandomIt last, Compare comp = Compare{}) {
    if (first == last) return;
    quick_sort(first, last, comp);
}


void solve() {
    int len; cin >> len;
    vi a(len); for(int &x : a) cin >> x;

    Sort(a.begin(), a.end());

    for(int &x : a) cout << x << " ";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    // cin >> t;		// multi testcases
    t = 1;  // single testcase

    while (t--) {
        solve();
    }

    return 0;
}