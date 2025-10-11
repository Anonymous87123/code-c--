#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << 0;
        return 0;
    } 
    int binary = 0;
    int power = 1; // 当前位的权重
    while (n > 0) {
        int remainder = n % 2;  // 获取当前最低位
        binary += remainder * power;
        power *= 10;            // 下一位的权重
        n /= 2;                 // 去掉已处理的最低位
    } 
    cout << binary;
    return 0;
}