#include<iostream>
#include<vector>
using namespace std;
vector<int> add(vector<int> a, vector<int> b) {
    int base;
    cin >> base;
    vector<int> result;
    long long carry = 0;
    int len = max(a.size(), b.size());
    for (int i = 0; i < len; i++) {
        long long digitA = (i < a.size()) ? a[i] : 0;//多余高位补0
        long long digitB = (i < b.size()) ? b[i] : 0;//多余高位补0
        long long sum = digitA + digitB + carry;
        result.push_back(sum % base);
        carry = sum / base;
    }
    if (carry) {
        result.push_back(carry);
    }
    return result;
}
void printNumber(vector<int> num) 
{
    if (num.empty()) {
        cout << "0";
        return;
    }
    cout << num.back();
    for (int i = num.size() - 2; i >= 0; i--) {
        cout <<  num[i];
    }
    cout << endl;
}
int main()
{
    vector<int> a, b;
    cin >> a >> b;
    vector<int> c = add(a, b);
    printNumber(c);
    return 0;
}