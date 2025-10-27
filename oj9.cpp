#include <iostream>
#include <cmath>
#include <climits>
#include <iomanip>
using namespace std;

int main() {
    int m, n, p;
    while (cin >> m >> n >> p) {
        bool overflow = false;
        
        // 计算 sum1 = 1⁵ + 2⁵ + ... + p⁵
        long long sum1 = 0;  // 改用 long long 避免溢出
        for (int i = 1; i <= p; i++) {
            sum1 += pow(i, 5);
            if (sum1 > INT_MAX) {
                overflow = true;
                break;  // 立即终止循环
            }
        }

        // 计算 sum2 = 1 + 2 + ... + m
        long long sum2 = 0;
        for (int j = 1; j <= m; j++) {
            sum2 += j;
            if (sum2 > INT_MAX) {
                overflow = true;
                break;
            }
        }

        // 计算 sum3 = 1³ + 2³ + ... + n³
        long long sum3 = 0;
        for (int k = 1; k <= n; k++) {
            sum3 += pow(k, 3);
            if (sum3 > INT_MAX) {
                overflow = true;
                break;
            }
        }

        // 检查 sum2 + sum3 是否溢出
        if (sum2 + sum3 > INT_MAX) {
            overflow = true;
        }

        // 输出结果
        if (overflow) {
            cout << "Overflow" << endl;
        } else {
            double result = double(sum2 + sum3) / double(sum1);
            cout << fixed << setprecision(4) << result << endl;
        }
    }
    return 0;
}