#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
int main() {
    int n, m, c;
    cin >> n >> m >> c;
    int N = max({n, m, c});
    // 预计算组合数 C[i][j] = C(i, j) mod MOD
    vector<vector<int>> C(N + 1, vector<int>(N + 1, 0));
    for (int i = 0; i <= N; ++i) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; ++j)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
    }
    int nm = n * m;
    vector<int> inner(nm + 1, 0);
    // 计算 inner[t] = Σ (-1)^s * C(c, s) * (s+1)^t
    for (int s = 0; s <= c; ++s) {
        int coeff = C[c][s];
        if (s & 1) coeff = MOD - coeff;          // 处理负号
        int base = s + 1;
        int cur = 1;                             // (s+1)^0
        inner[0] = (inner[0] + (ll)coeff * cur) % MOD;
        for (int t = 1; t <= nm; ++t) {
            cur = (ll)cur * base % MOD;          // (s+1)^t
            inner[t] = (inner[t] + (ll)coeff * cur) % MOD;
        }
    }
    ll S = 0;
    for (int a = 0; a <= n; ++a) {
        int comb_n_a = C[n][a];
        for (int b = 0; b <= m; ++b) {
            int comb_m_b = C[m][b];
            int t = a * b;
            int val = inner[t];
            ll term = (ll)comb_n_a * comb_m_b % MOD * val % MOD;
            if ((a + b) & 1) term = MOD - term;  // 乘以 (-1)^(a+b)
            S = (S + term) % MOD;
        }
    }
    if ((c + n + m) & 1) S = MOD - S;            // 乘以 (-1)^(c+n+m)
    cout << S % MOD << endl;
    return 0;
}