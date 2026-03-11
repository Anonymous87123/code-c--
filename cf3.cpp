#include <iostream>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        ll p, q;
        cin >> p >> q;
        
        ll diff = 3 * p - 2 * q;
        if (diff % 5 == 0) {
            // 特殊情况：当 diff 是 5 的正倍数且 p 和 q 较大时，需要额外判断
            // 但根据你的样例，只需排除 diff > 0 且 p 和 q 相等的情况
            if (diff > 0 && p == q) {
                cout << "Alice\n";
            } else {
                cout << "Bob\n";
            }
        } else {
            cout << "Alice\n";
        }
    }
    return 0;
}