#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> p(n), a(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        vector<int> pos(n + 1);
        for (int i = 0; i < n; i++) {
            pos[p[i]] = i;
        }
        
        bool ok = true;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] != a[i + 1] && pos[a[i]] > pos[a[i + 1]]) {
                ok = false;
                break;
            }
        }
        
        cout << (ok ? "YES" : "NO") << "\n";
    }
    
    return 0;
}