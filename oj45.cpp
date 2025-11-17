#include <iostream>
#include <vector>
using namespace std;
void printbase(unsigned long long num, unsigned int base) {
    if (num == 0) {
        cout << "0" << endl;
        return;
    }
    vector<char> result;
    while (num > 0) {
        int temp = num % base;
        if (temp < 10) {
            result.push_back(temp + '0');
        } else {
            result.push_back(temp - 10 + 'A');
        }
        num /= base; // 直接除以 base，不需要 num -= temp
    }
    for (int i = result.size() - 1; i >= 0; i--) {
        cout << result[i];
    }
    cout << endl;
}
int main() {
    unsigned long long num;
    unsigned int base;
    while (cin >> num >> base) {
        printbase(num, base);
    }
    return 0;
}