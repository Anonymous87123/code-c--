//我们定义状态 dp[i][j]表示经过 i次传球后，球在编号为 j的同学手里的方法数。由于同学们站成一个圆圈，需要注意边界情况（1 号同学左边是 n 号，n 号同学右边是 1 号）
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    int dp[31][31] = {0};  // dp[i][j] 表示传 i 次到 j 的方法数
    dp[0][1] = 1;  // 初始状态：0 次传球时球在 1 号（小蛮）手里
    for (int i = 1; i <= m; i++) {          // 传球次数
        for (int j = 1; j <= n; j++) {     // 当前持球人
            int left, right;
            // 计算 j 的左边和右边（注意圆圈处理）其中 left(j)是 j 左边的同学编号，right(j)是 j 右边的同学编号
            if (j == 1) {
                left = n;
            } else {
                left = j - 1;
            }
            if (j == n) {
                right = 1;
            } else {
                right = j + 1;
            }
            // 状态转移
            dp[i][j] = dp[i-1][left] + dp[i-1][right];
        }
    }
    cout << dp[m][1] << endl;  // 传 m 次回到 1 号的方法数
    return 0;
}