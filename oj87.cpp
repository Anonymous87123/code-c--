#include <bits/stdc++.h>
using namespace std;
class FilePath {
public:
    string path;
    FilePath(string p) : path(p) {}
    string simplifyPath() {
        vector<string> stk;
        stringstream ss(path);
        string part;
        while (getline(ss, part, '/')) {
            if (part.empty() || part == ".") {
                continue;
            } else if (part == "..") {
                if (!stk.empty()) {
                    stk.pop_back();
                }
            } else {
                stk.push_back(part);
            }
        }
        string res;
        for (const string& dir : stk) {
            res += "/" + dir;
        }
        return res.empty() ? "/" : res;
    }
};
int main() {
    string path;
    while (cin >> path) {
        FilePath fp(path);
        cout << fp.simplifyPath() << endl;
    }
    return 0;
}