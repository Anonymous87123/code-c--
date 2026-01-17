#include <bits/stdc++.h>
using namespace std;
const int MAX_A = 25000;// 最大面额
int dp[MAX_A + 5];// dp[j] 表示金额 j 能否被表示
int main() {
    int T;//数据的组数
    cin >> T;
    while (T--) {
        int n;//面额类数
        cin >> n;
        int a[105];//分别是多少面额
        int max_a = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] > max_a) max_a = a[i];
        }
        sort(a, a + n);
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;//0可以表示
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (dp[a[i]]) continue;// 当前面额能被之前的数表示，则跳过
            ans++;                     // 否则，当前面额是必要的
            // 完全背包更新
            for (int j = a[i]; j <= max_a; j++) {
                dp[j] |= dp[j - a[i]];
            }
        }
        cout << ans << endl;
    }
    return 0;
}