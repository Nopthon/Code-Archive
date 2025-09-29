// For VSCode Coding
#include <bits/stdc++.h>
using namespace std;
//

/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */

// @lc code=start

// 直接给出两种原地算法的方案
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // 第一种：反转数组
        // 对于一个数字 nums[i] -> nums[(i+k)%n]
        // 我们记前 n-k 个元素为 A，后 k 个元素为 B，翻转运算为符号 '
        // 则 AB -> (AB)' == B'A' -> BA' -> BA
        // 不难证明三次翻转的算法正确性
        // reverse 采用 swap 方案翻转数组，空间复杂度为 O(1)
        // 每个元素被翻转两次，时间复杂度 O(2n) = O(n)
        int n = nums.size();
        k %= n;
        reverse(nums.begin(), nums.end());
        // 注意“左闭右开”特性
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
        return;
    }
};

class Another_Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // 第二种：跳跃交换
        // 从抽象代数的角度来看，长度为 n 的数组右移 k 位，
        // 相当于 Z/kZ 所有商环上的加法平移
        // 通俗的说：将所有 a[i], a[(i+k)%n], ..., a[(i+nk)%n] 串成一个环
        // 从不同的起点出发能串成的所有的环就是商环的集合
        // 进行轮转时，每个环内的元素只需要进行一次加法平移即可（右移一位）
        // 时间复杂度 O(n)
        // （不难证明总共有 gcd(n,k) 个环）
        // （对于 gcd(n,k) == 1 的情况，我们称移位为循环置换）
        int n = nums.size();
        k %= n;
        int cnt = gcd(n, k);
        for (int i = 0; i < cnt; i++) {
            int cur = i;
            int prev = nums[i];
            do {
                int next = (cur + k) % n;
                swap(nums[next], prev);
                cur = next;
            } while (cur != i);
        }

        return;
    }
};
// @lc code=end

// 考虑内存访问，编译器优化的角度，第一种方案有时会有比第二种方案更优的性能