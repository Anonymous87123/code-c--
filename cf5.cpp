#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll, pair<bool, vector<int>>> cache;
pair<bool, vector<int>> query(ll k, bool use_cache = true) {
    if (use_cache && cache.count(k)) {
        return cache[k];
    }
    cout << "? " << k << endl;
    cout.flush();
    int q;
    cin >> q;
    if (q == 0) {
        cache[k] = {false, {}};
        return {false, {}};
    }
    vector<int> path(q);
    for (int i = 0; i < q; i++) {
        cin >> path[i];
    }
    cache[k] = {true, path};
    return {true, path};
}

void solve() {
    int n;
    cin >> n;
    cache.clear();
    ll K = 0;
    {
        ll l = 1, r = 1LL << 30;
        while (l <= r) {
            ll mid = (l + r) / 2;
            auto [exist, _] = query(mid, false);
            if (exist) {
                K = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
    }
    vector<ll> f(n + 1, 0), start(n + 1, 0);
    for (int v = 1; v <= n; v++) {
        start[v] = 1;
        for (int i = 1; i < v; i++) {
            start[v] += f[i];
        }
        ll l = start[v], r = K;
        while (l < r) {
            ll mid = (l + r + 1) / 2;
            auto [exist, path] = query(mid);
            if (exist && !path.empty() && path[0] == v) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        f[v] = l - start[v] + 1;
    }
    vector<pair<int, int>> edges;
    for (int v = 1; v <= n; v++) {
        ll s = start[v];
        ll pos = s + 1;
        while (pos <= s + f[v] - 1) {
            auto [exist, path] = query(pos);

            int w = path[1];
            edges.push_back({v, w});
            pos += f[w];
        }
    }
    cout << "! " << edges.size() << endl;
    for (auto [u, v] : edges) {
        cout << u << " " << v << endl;
    }
    cout.flush();
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}