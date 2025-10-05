#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
const int BASE = 10000; // 万进制
vector<int> multiply(vector<int> num, int multiplier) {
    long long carry = 0;
    for (int i = 0; i < num.size(); i++) {
        long long product = (long long)num[i] * multiplier + carry;
        num[i] = product % BASE;
        carry = product / BASE;
    }
    while (carry) {
        num.push_back(carry % BASE);
        carry /= BASE;
    }//数位前面幂次小，后面幂次大
    return num;
}
// 高精度加法（万进制）
vector<int> add(vector<int> a, vector<int> b) {
    vector<int> result;
    long long carry = 0;
    int len = max(a.size(), b.size());
    for (int i = 0; i < len; i++) {
        long long digitA = (i < a.size()) ? a[i] : 0;//多余高位补0
        long long digitB = (i < b.size()) ? b[i] : 0;//多余高位补0
        long long sum = digitA + digitB + carry;
        result.push_back(sum % BASE);
        carry = sum / BASE;
    }
    if (carry) {
        result.push_back(carry);
    }
    return result;
}
// 格式化输出（补前导零）
void printNumber(vector<int> num) {
    if (num.empty()) {
        cout << "0";
        return;
    }
    // 输出最高位
    cout << num.back();
    // 输出其余位（补前导零）
    for (int i = num.size() - 2; i >= 0; i--) {
        cout << setfill('0') << setw(4) << num[i];
    }
    cout << endl;
}
int main() {
    int n;
    cin >> n;
    vector<int> factorial = {1}; // 1! = 1
    vector<int> total = {0};     // 总和
    for (int i = 1; i <= n; i++) {
        factorial = multiply(factorial, i);
        total = add(total, factorial);
    }
    printNumber(total);
    return 0;
}