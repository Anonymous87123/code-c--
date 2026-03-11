#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> left(n + 1, 0), right(n + 1, 0), parent(n + 1, -1);
    // 读入顶点 1..n 的信息
    for (int i = 1; i <= n; ++i) {
        int l, r;
        cin >> l >> r;
        left[i] = l;
        right[i] = r;
        if (l != 0) parent[l] = i;
        if (r != 0) parent[r] = i;
    }

    // 找出根 0 的孩子（父节点仍为 -1 的顶点）
    vector<int> roots;
    for (int i = 1; i <= n; ++i) {
        if (parent[i] == -1) roots.push_back(i);
    }
    sort(roots.begin(), roots.end());
    // 构造根 0 的孩子
    left[0] = roots.size() > 0 ? roots[0] : 0;
    right[0] = roots.size() > 1 ? roots[1] : 0;
    for (int r : roots) parent[r] = 0;
    parent[0] = -1;

    vector<int> order;          // 全局遍历序列（每一步后的位置）
    vector<int> first(n + 1, -1);
    vector<int> state(n + 1, 0); // 0:空, 1:L, 2:R

    int cur = 0;
    int t = 0;
    order.push_back(cur);
    first[cur] = t;

    while (true) {
        int nxt = -1;
        if (left[cur] == 0 && right[cur] == 0) { // 叶子
            nxt = parent[cur];
        } else {
            if (state[cur] == 0) {
                if (left[cur] == 0) break;      // 无左孩子，无法移动
                nxt = left[cur];
                state[cur] = 1;
            } else if (state[cur] == 1) {
                if (right[cur] == 0) break;     // 无右孩子，无法移动
                nxt = right[cur];
                state[cur] = 2;
            } else { // state == 2
                if (parent[cur] == -1) break;   // 无父节点（根）
                nxt = parent[cur];
                state[cur] = 0;
            }
        }
        if (nxt == -1) break;   // 安全保护
        cur = nxt;
        ++t;
        order.push_back(cur);
        if (first[cur] == -1) first[cur] = t;
    }

    // 回答查询
    for (int i = 0; i < q; ++i) {
        int v, k;
        cin >> v >> k;
        int pos = first[v] + k;
        cout << order[pos] << (i + 1 == q ? '\n' : ' ');
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}