#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Ternary {
private:
    vector<int> digits; 
public:
    Ternary(int num) {
        if (num == 0) {
            digits.push_back(0);
            return;
        }
        while (num > 0) {
            digits.push_back(num % 3);
            num /= 3;
        }
    }
    // 重载[]运算符：访问指定下标的三进制位（最低位下标为0）
    int operator[](int idx) const {
        if (idx >= 0 && idx < digits.size()) {
            return digits[idx];
        }
        return 0; 
    }
    Ternary operator+(const Ternary& other) const {
        Ternary res(0);
        res.digits.clear();
        int carry = 0;
        int max_len = max(digits.size(), other.digits.size());
        for (int i = 0; i < max_len || carry; ++i) {
            int d1 = (i < digits.size()) ? digits[i] : 0;
            int d2 = (i < other.digits.size()) ? other.digits[i] : 0;
            int sum = d1 + d2 + carry;
            res.digits.push_back(sum % 3);
            carry = sum / 3;
        }
        return res;
    }
    void display() const {
        for (int i = digits.size() - 1; i >= 0; --i) {
            cout << digits[i];
        }
        cout << endl;
    }
    friend ostream& operator<<(ostream& os, const Ternary& t) {
        os << t.digits[0];
        return os;
    }
};
int main() {
    int num1, num2;
    cin >> num1 >> num2;
    Ternary t1(num1), t2(num2);
    cout << t1[0] << ' ' << t2[0] << '\n';
    t1.display();
    t2.display();
    Ternary t3 = t1 + t2;
    t3.display();
    t1.display();
    return 0;
}