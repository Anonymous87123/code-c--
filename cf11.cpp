#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t;cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> left(n + 1), right(n + 1), parent(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            int l, r;cin >> l >> r;
            left[i] = l;right[i] = r;
            if (l) parent[l] = i;
            if (r) parent[r] = i;
        }
        parent[1] = 0;
        vector<ll> h(n + 1, 0), sum(n + 1, 0);
        vector<int> cnt(n + 1, 0);
        queue<int> q;
        for (int i = 1; i <= n; ++i) {
            if (left[i] == 0 && right[i] == 0) {
                h[i] = 1;
                q.push(i);
            }
        }
        while (!q.empty()) {
            int v = q.front(); q.pop();
            int p = parent[v];
            if (p != 0) {
                sum[p] = (sum[p] + h[v]) % MOD;
                ++cnt[p];
                if (cnt[p] == 2) {
                    h[p] = (sum[p] + 3) % MOD;
                    q.push(p);
                }
            }
        }
        vector<ll> ans(n + 1, 0);
        ans[1] = h[1] % MOD;
        queue<int> bfs;
        bfs.push(1);
        while (!bfs.empty()) {
            int u = bfs.front(); bfs.pop();
            if (left[u]) {
                ans[left[u]] = (ans[u] + h[left[u]]) % MOD;
                bfs.push(left[u]);
            }
            if (right[u]) {
                ans[right[u]] = (ans[u] + h[right[u]]) % MOD;
                bfs.push(right[u]);
            }
        }
        for (int i = 1; i <= n; ++i) {
            cout << ans[i];
            if (i < n) cout << ' ';
        }
        cout << '\n';
    }
}