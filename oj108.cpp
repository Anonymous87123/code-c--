#include<bits/stdc++.h>
using namespace std;
string replaceall(string str, string old_str, string new_str) {
    if (old_str.empty()) return str; // 防止死循环
    int start_pos = 0;
    while ((start_pos = str.find(old_str, start_pos)) != string::npos) {
        str.replace(start_pos, old_str.length(), new_str);
        start_pos += new_str.length(); 
    }
    return str;
}
int main() {
	string old_str, new_str, line;
	int n;
	while (cin >> n) { 
		cin.ignore();
		getline(cin, old_str); // 要替换的字符串
		getline(cin, new_str); // 替换后的字符串
		for (int i = 0; i < n; i++) {
			getline(cin, line);
			string new_line = replaceall(line, old_str, new_str);
			cout << new_line << endl;
		}
	}
	return 0;
}