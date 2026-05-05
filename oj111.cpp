#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    while (cin >> n >> m) {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int max_side = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                int val;
                cin >> val;
                if (val == 1) {
                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                    max_side = max(max_side, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        cout << max_side << "\n";
    }
    return 0;
}