#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    while (cin >> n) {
        cin.ignore();
        string line;
        getline(cin, line);
        vector<int> arr;
        int num = 0;
        bool inNumber = false;
        for (char c : line) {
            if (c >= '0' && c <= '9') {
                // 当前字符是数字
                num = num * 10 + (c - '0');
                inNumber = true;
            } else if (inNumber) {
                // 遇到非数字字符，且之前正在解析数字
                arr.push_back(num);
                num = 0;
                inNumber = false;
            }
        }
        if (inNumber) {
            arr.push_back(num);
        }
        int target;
        cin >> target;
        int left = 0, right = n - 1;
        bool found = false;
        while (left < right) {
            int sum = arr[left] + arr[right];
            if (sum == target) {
                found = true;
                break;
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        if (found) {
            cout << "TRUE" << endl;
        } else {
            cout << "FALSE" << endl;
        }
    }
    
    return 0;
}