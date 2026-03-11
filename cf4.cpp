#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        int B = (int)sqrt(n) + 1;
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > B) {
                for (int v = 1; v <= B; v++) {
                    ll j = i + (ll)a[i] * v;
                    if (j >= n) break;
                    if (a[j] == v) {
                        ans++;
                    }
                }
            }
        }
        for (int j = 0; j < n; j++) {
            for (int x = 1; x <= B; x++) {
                ll i = j - (ll)a[j] * x;
                if (i < 0) break;
                if (a[i] == x) {
                    ans++;
                }
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}