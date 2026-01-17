#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
int main() {
    int N, T;
    cin >> N >> T;
    // 分组：键为方向 (dx, dy)，值为该方向上的点，每个点存储 (距离平方, 时间, 价值)
    map<pair<int, int>, vector<array<int, 3>>> groups;
    for (int i = 0; i < N; ++i) {
        int x, y, t, v;
        cin >> x >> y >> t >> v;
        int g = gcd(abs(x), abs(y));// 修改为使用y的绝对值
        int dx = x / g, dy = y / g;// 方向向量
        groups[{dx, dy}].push_back({x * x + y * y, t, v});
    }
    // 对每组生成物品：前缀和 (总时间, 总价值)
    vector<vector<pair<int, int>>> items;
    for (auto &[dir, vec] : groups) {
        sort(vec.begin(), vec.end());   // 按距离平方排序
        vector<pair<int, int>> group;
        int sum_t = 0, sum_v = 0;
        for (auto &[d2, t, v] : vec) {
            sum_t += t;
            sum_v += v;
            group.emplace_back(sum_t, sum_v);
        }
        items.push_back(group);
    }
    // 分组背包 DP
    vector<int> dp(T + 1, 0);
    for (auto &group : items) {
        vector<int> newdp = dp;// 保存本组之前的状态
        for (auto &[time, val] : group) {
            for (int j = T; j >= time; --j) {
                newdp[j] = max(newdp[j], dp[j - time] + val);
            }
        }
        dp = move(newdp);
    }
    int ans = 0;
    for (int i = 0; i <= T; ++i) {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}