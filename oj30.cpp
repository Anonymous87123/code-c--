#include <bits/stdc++.h>
using namespace std;
bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first != b.first) {
        return a.first > b.first;  
    } else {
        return a.second < b.second; 
    }
}
int main() {
    int n;
    vector<vector<pair<int, int>>> allGroups;
    while (cin >> n) {
        vector<pair<int, int>> group(n);
        for (int i = 0; i < n; i++) {
            cin >> group[i].first;
            group[i].second = i;
        }
        allGroups.push_back(group);
    }
    for (auto& group : allGroups) {
        sort(group.begin(), group.end(), compare);
        for (int i = 0; i < group.size(); i++) {
            cout << group[i].first << " " << group[i].second;
            if (i != group.size() - 1) {
                cout << "  "; 
            }
        }
        cout << endl; 
    }
    return 0;
}