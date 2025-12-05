#include <iostream>
#include <iomanip>
using namespace std;

void printBinary(int num) {
    for (int i = 31; i >= 0; i--) {
        // 获取第i位的值
        int bit = (num >> i) & 1;
        cout << bit;
    }
}

int main() {
    int num;
    while (cin >> num) {
        cout << "before shift: ";
        printBinary(num);
        cout << endl;
        
        int shifted = num >> 4;
        
        cout << "after shift: ";
        printBinary(shifted);
        cout << endl;
    }
    return 0;
}