#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;
const int N = 50000;
const int M = 200;
int stir[N + 5][M + 5];
int C[M + 5][M + 5];
void init() {
    stir[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        stir[i][0] = 0;
        for (int j = 1; j <= min(i, M); j++) {
            stir[i][j] = (stir[i-1][j-1] + (long long)(i-1) * stir[i-1][j] % MOD) % MOD;
        }
    }
    C[0][0] = 1;
    for (int i = 1; i <= M; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++) {
            C[i][j] = (C[i-1][j] + C[i-1][j-1]) % MOD;
        }
    }
}
main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int T;
    cin >> T;
    while (T--) {
        int n, A, B;
        cin >> n >> A >> B;
        if (A + B - 2 > n - 1) {
            cout << 0 << "\n";
            continue;
        }
        int ans = stir[n-1][A+B-2] * C[A+B-2][A-1] % MOD;
        cout << ans << "\n";
    }
    return 0;
}