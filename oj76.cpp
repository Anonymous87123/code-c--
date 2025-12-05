#include<bits/stdc++.h>
using namespace std;
int main() {
    string s;
    while (cin >> s) {
        int result = 0;
        char op = '+';
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) 
            {
                int num = s[i] - '0';
                if (i + 1 < s.size() && s[i + 1] == '*') 
                {
                    num *= (s[i + 2] - '0');
                    i += 2;
                }
                if (op == '+') result += num;
                else if (op == '-') result -= num;
            } 
            else 
            {
                op = s[i]; 
            }
        }
        cout << result << endl;
    }
    return 0;
}