#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(2 * n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i];  // 破环成链，复制一遍
    }
    // 利用前缀和维护某一段的和
    vector<int> sum(2 * n + 1, 0);
    for (int i = 1; i <= 2 * n; i++) {
        sum[i] = sum[i - 1] + a[i];
    }
    // dp数组初始化
    vector<vector<int>> dp_min(2 * n + 1, vector<int>(2 * n + 1, INT_MAX));
    vector<vector<int>> dp_max(2 * n + 1, vector<int>(2 * n + 1, INT_MIN));
    for (int i = 1; i <= 2 * n; i++) {
        dp_min[i][i] = 0;
        dp_max[i][i] = 0;
    }
    // 区间DP
    for (int len = 2; len <= n; len++) {           // 枚举区间长度
        for (int i = 1; i + len - 1 <= 2 * n; i++) { // 枚举起点
            int j = i + len - 1;                     // 终点
            for (int k = i; k < j; k++) {            // 枚举分割点
                int cost = sum[j] - sum[i - 1];      // 合并[i,j]的代价
                dp_min[i][j] = min(dp_min[i][j], dp_min[i][k] + dp_min[k + 1][j] + cost);
                dp_max[i][j] = max(dp_max[i][j], dp_max[i][k] + dp_max[k + 1][j] + cost);
            }
        }
    }
    // 遍历所有起点，找到最小和最大得分
    int min_score = INT_MAX, max_score = INT_MIN;
    for (int i = 1; i <= n; i++) {
        min_score = min(min_score, dp_min[i][i + n - 1]);
        max_score = max(max_score, dp_max[i][i + n - 1]);
    }
    cout << min_score << endl;
    cout << max_score << endl;
    return 0;
}