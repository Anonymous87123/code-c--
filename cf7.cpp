#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> cnt;
vector<bool> processed;          
vector<pair<int, int>> edges;   
unordered_map<long long, vector<int>> cache;
vector<int> query(long long k) {
    if (cache.count(k)) return cache[k];
    cout << "? " << k << endl;
    fflush(stdout);
    int q;
    cin >> q;
    if (q == 0) {
        cache[k] = {};
        return {};
    }
    vector<int> path(q);
    for (int i = 0; i < q; ++i) cin >> path[i];
    cache[k] = path;
    return path;
}

int dfs(int v, long long base, int depth) {
    if (processed[v]) return cnt[v];
    processed[v] = true;
    int total = 1;
    long long offset = 1;
    while (true) {
        long long k = base + offset;
        vector<int> path = query(k);
        if (path.empty()) break;
        if ((int)path.size() < depth) break;
        if (path[depth - 1] != v) break;
        if ((int)path.size() == depth) break;
        int u = path[depth]; 
        edges.emplace_back(v, u);

        int cu;
        if (!processed[u]) {
            cu = dfs(u, k, depth + 1);
        } else {
            cu = cnt[u];
        }
        total += cu;
        offset += cu;
    }
    cnt[v] = total;
    return total;
}

void solve() {
    cin >> n;
    cnt.assign(n + 1, 0);
    processed.assign(n + 1, false);
    edges.clear();
    cache.clear();

    for (int v = 1; v <= n; ++v) {
        if (!processed[v]) {
            long long start = 1;
            for (int i = 1; i < v; ++i) start += cnt[i];
            dfs(v, start, 1);
        }
    }
    cout << "! " << edges.size() << "\n";
    for (auto &e : edges) {
        cout << e.first << " " << e.second << "\n";
    }
    cout.flush();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}