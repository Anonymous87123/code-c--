#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<int, int>> edges;
vector<ll> f;
vector<ll> start;
vector<bool> known;
vector<vector<int>> adj;
ll total_paths = 0;
int n;
map<ll, pair<bool, vector<int>>> cache;

pair<bool, vector<int>> query(ll k) {
    if (cache.count(k)) return cache[k];
    cout << "? " << k << endl;
    cout.flush();
    int q;
    cin >> q;
    if (q == 0) {
        cache[k] = {false, {}};
        return {false, {}};
    }
    vector<int> path(q);
    for (int i = 0; i < q; i++) cin >> path[i];
    cache[k] = {true, path};
    return {true, path};
}

void process(int v) {
    if (known[v]) return;
    start[v] = 1;
    for (int i = 1; i < v; i++) {
        if (known[i]) start[v] += f[i];
    }
    auto [exist0, path0] = query(start[v]);
    ll offset = 1;
    while (true) {
        ll idx = start[v] + offset;
        auto [exist, path] = query(idx);
        if (!exist) break;
        if (path[0] != v) break;
        if (path.size() >= 2) {
            int w = path[1];
            edges.push_back({v, w});
            process(w);
            offset += f[w];
        } else {
            break;
        }
    }
    f[v] = offset;
    known[v] = true;
}

void solve() {
    cin >> n;
    edges.clear();
    f.assign(n + 1, 0);
    start.assign(n + 1, 0);
    known.assign(n + 1, false);
    cache.clear();
    for (int v = 1; v <= n; v++) {
        process(v);
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