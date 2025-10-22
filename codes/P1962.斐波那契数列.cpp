/* Title: P1962 斐波那契数列
 *
 * From Luogu: https://www.luogu.com.cn/problem/P1962
 *
 * Record: https://www.luogu.com.cn/record/242027412
*/

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()	// sort(all(v), cmp);
#define pb push_back					// vector.pb(1);

// #define int long long
constexpr int MOD = 1000000007;

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;

struct Matrix{
	vector<vector<int>> mat;									// 矩阵
    int rows, cols;												// 行列数据
    
    // 构造函数，使得在创建Matrix的时候可以像STL容器一样指定行列
    // rows(rows), cols(cols) 是初始化列表，用于右侧的初始化（两个rows/cols实质不同）: mat(rows, vector<int>(cols))
	Matrix(int rows, int cols) : rows(rows), cols(cols), mat(rows, vector<int>(cols)) {}
    
    vector<int>& operator[](int index) {						// 重载[]运算符进行对矩阵元素的访问
        return mat[index];
    }
    
    // 如果定义了一个 const Matrix，必须要定义一个const版本的[]重载 （对*的重载就用到了const版本的[]重载）
    const vector<int>& operator[](int index) const {
        return mat[index];
    }
};

// 重载*运算符实现矩阵乘法运算
Matrix operator*(const Matrix& a, const Matrix& b) {
    Matrix result(a.rows, b.cols);
    // 这里忽略了行列合法性检查
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < b.cols; j++) {
            int sum = 0;
            for (int k = 0; k < a.cols; k++) {
                sum = (sum + (long long)(a[i][k]) * b[k][j]) % MOD;  			// 进行点积计算
            }
            result[i][j] = sum;
        }
    }
    return result;
}

Matrix matrix_pow(Matrix base, long long exp) {
    int n = base.rows;
    // 初始化单位矩阵
    Matrix result(n,n);
    for(int i = 0; i < n; i++) result[i][i] = 1;
    // 快速幂算法
    while (exp > 0) {
        if (exp & 1) {                     // 如果指数是奇数
            result = result * base;
        }
        base = base * base;  // 底数平方
        exp >>= 1;                         // 指数除以2
    }
    
    return result;
}

void solve() {
    ll n; cin >> n; 
	if(n <= 1){
		cout << n; return;
    }
    
	Matrix A(2,2);
	A[0][0] = A[0][1] = A[1][0] = 1, A[1][1] = 0;
	A = matrix_pow(A, n-1);

	Matrix B(2,1);
	B[0][0] = 1; B[1][0] = 0;

	Matrix C = A * B;

	cout << C[0][0];
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