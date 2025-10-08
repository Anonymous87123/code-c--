//程序输入x,y，既然P,Q 以x为最大公约数，那么它们各除以 x 后一定互素，可以设P=mx，Q=nx，则gcd(m,n)=1，gcd(P,Q)=x，lcm(P,Q)=mxn=y，所以mn=y/x，所以只用枚举y/x的因数对，当因数对互素的时候，计数器增加2，注意当x=y时应该事先减一再枚举一次
#include <iostream>
using namespace std;
// 使用欧几里得算法计算最大公约数
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
// 通过数学关系计算最小公倍数
int lcm(int a, int b) {
    return a / gcd(a, b) * b; // 先除后乘避免溢出
}
int main() {
    int n, m;
    cin >> n >> m;
    // 如果m不能被n整除，则无解
    if (m % n != 0) {
        cout << 0 << endl;
        return 0;
    }
    int count = 0;
    int k = m / n; // i*j = n² * k
    int low = min(n, m);
    int high = max(n, m);
    // 枚举k的因数
    for (int a = 1; a * a <= k; a++) {
        if (k % a == 0) {
            int b = k / a;
            // 检查a和b是否互质
            if (gcd(a, b) == 1) {
                int i1 = n * a;
                int j1 = n * b;
                // 检查第一组解是否在范围内
                if (i1 >= low && i1 <= high && j1 >= low && j1 <= high) {
                    count++;
                }
                // 如果a≠b，检查第二组解
                if (a != b) {
                    int i2 = n * b;
                    int j2 = n * a;
                    if (i2 >= low && i2 <= high && j2 >= low && j2 <= high) {
                        count++;
                    }
                }
            }
        }
    }
    cout << count << endl;
    return 0;
}