#include <bits/stdc++.h>
using namespace std;
void cmp(const string& pattern, vector<int>& next) {
    int m = pattern.length();
    next.resize(m);
    next[0] = 0;
    int j = 0;
    for (int i = 1; i < m; i++) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = next[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            j++;
        }
        next[i] = j;
    }
}
void kmp(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();
    vector<int> next;
    cmp(pattern, next);
    int j = 0; 
    for (int i = 0; i < n; i++) {
        while (j > 0 && text[i] != pattern[j]) j = next[j - 1];
        if (text[i] == pattern[j]) j++;
        if (j == m) {
            cout << i - m + 2 << "\n";
            j = next[j - 1];
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string text, pattern;
    cin >> text >> pattern;
    kmp(text, pattern);
    vector<int> next;
    cmp(pattern, next);
    for (int i = 0; i < next.size(); i++) {
        cout << next[i] << " ";
    }
    cout << "\n";
    return 0;
}