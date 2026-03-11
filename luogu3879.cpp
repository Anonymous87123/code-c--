#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M, L;
    string word;
    unordered_map<string, vector<int>> mp;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> L;
        unordered_set<string> seen;
        for (int j = 0; j < L; ++j) {
            cin >> word;
            if (seen.find(word) == seen.end()) {
                seen.insert(word);
                mp[word].push_back(i);
            }
        }
    }
    cin >> M;
    for (int i = 0; i < M; ++i) {
        cin >> word;
        if (mp.find(word) != mp.end()) {
            for (size_t j = 0; j < mp[word].size(); ++j) {
                if (j) cout << " ";
                cout << mp[word][j];
            }
        }
        cout << "\n";
    }
    return 0;
}