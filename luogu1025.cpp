#include <iostream>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    int dp[201][7] = {0}; // 初始化数组为0，n最大200，k最大6
    // 初始化边界：将i分成1份只有一种分法
    for (int i = 1; i <= n; i++) {
        dp[i][1] = 1;
    }
    // 动态规划递推
    for (int j = 2; j <= k; j++) {
        for (int i = j; i <= n; i++) { // i至少为j，否则无法划分
            dp[i][j] = dp[i-1][j-1] + dp[i-j][j];
        }
    }
    //定义的dp[i][j]表示将i分成j份的方案数，每份不为空，不考虑顺序；
    //如果其中有一份为1，则剩下的i-1分成j-1份；
    //如果每份至少为2，则每份先拿出1，此时总和为i-j，剩下的再分成j份
    cout << dp[n][k] << endl;
    return 0;
}