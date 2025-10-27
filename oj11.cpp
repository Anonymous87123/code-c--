#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main() {
    double x;
    int n;
    while (cin >> x >> n) {
        double p[n + 1];
        p[0] = 1.00;
        p[1] = x;
        for (int i = 2; i <= n; i++) {
            p[i] = ((2 * i - 1) * p[i - 1] - (i - 1) * p[i - 2]) / i;
        }
        double result = round(p[n] * 100 - 1e-4) / 100.0;
        cout << fixed << setprecision(2) << result << endl;
    }
    return 0;
}