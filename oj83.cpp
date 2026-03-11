#include<bits/stdc++.h>
using namespace std;
class STR {
private:
    char* p;
public:
    STR(char s[]) {
        int len = strlen(s);
        p = new char[len + 1];
        strcpy(p, s);
    }
    void movechar(char& a, char& b) {
        char temp = a;
        a = b;
        b = temp;
    }
    void fun() {
        if (p == nullptr) return;
        int len = strlen(p);
        int i = 0, j = len - 1;
        while (i < j) {
            while (i < j && !isdigit(p[i])) {
                i++;
            }
            while (i < j && isdigit(p[i]) && isdigit(p[j])) {
                j--;
            }
            if (i < j) {
                movechar(p[i], p[j]);
                i++;
                j--;
            }
        }
    }
    ~STR() {
        if (p != nullptr) {
            delete[] p;
            p = nullptr;
        }
    }
    void print() {
        cout << p << endl;
    }
};
int main() {
    char input[100];
    while (cin.getline(input, 100)) {
        STR s(input);
        s.fun();
        s.print();
    }
    return 0;
}