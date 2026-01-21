#include<bits/stdc++.h>
using namespace std;
const int N = 200010;
int n, m, cnt;
int a[N], root[N];
vector<int> nums;
struct Node {
    int l, r, cnt;
} tr[N * 40];
int insert(int p, int l, int r, int x) {
    int q = ++cnt;
    tr[q] = tr[p];
    if (l == r) {
        tr[q].cnt++;
        return q;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) tr[q].l = insert(tr[p].l, l, mid, x);
    else tr[q].r = insert(tr[p].r, mid + 1, r, x);
    tr[q].cnt = tr[tr[q].l].cnt + tr[tr[q].r].cnt;
    return q;
}
int query(int p, int q, int l, int r, int k) {
    if (l == r) return l;
    int cnt = tr[tr[q].l].cnt - tr[tr[p].l].cnt;
    int mid = (l + r) >> 1;
    if (k <= cnt) return query(tr[p].l, tr[q].l, l, mid, k);
    else return query(tr[p].r, tr[q].r, mid + 1, r, k - cnt);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        nums.push_back(a[i]);
    }
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    root[0] = 0;
    cnt = 0;
    for (int i = 1; i <= n; i++) {
        int x = lower_bound(nums.begin(), nums.end(), a[i]) - nums.begin();
        root[i] = insert(root[i - 1], 0, nums.size() - 1, x);
    }
    while (m--) {
        int l, r, k;
        cin >> l >> r >> k;
        int idx = query(root[l - 1], root[r], 0, nums.size() - 1, k);
        cout << nums[idx] << "\n";
    }
    return 0;
}