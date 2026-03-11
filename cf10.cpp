#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> f(n + 1);
        for (int i = 1; i <= n; ++i) cin >> f[i];
        if (n == 2) {
            cout << f[2] << ' ' << f[1] << '\n';
            continue;
        }
        vector<ll> d(n + 1);
        for (int i = 1; i <= n - 1; ++i) d[i] = f[i + 1] - f[i];
        vector<ll> a(n + 1);
        ll M = 0;
        ll sum1 = 0;
        for (int i = 2; i <= n - 1; ++i) {
            a[i] = (d[i] - d[i - 1]) / 2;
            M += a[i];
            sum1 += a[i] * (i - 1);
        }
        a[n] = (f[1] - sum1) / (n - 1);
        a[1] = a[n] + d[1] + M;
        for (int i = 1; i <= n; ++i) {
            cout << a[i] << (i == n ? '\n' : ' ');
        }
    }
    return 0;
}