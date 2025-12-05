#include<bits/stdc++.h>
using namespace std;
int main() {
    string s;
    while(cin >> s) {
        stack<char> st;
        bool valid = true;
        for(char c : s) 
        {
            if(c == '(' || c == '[' || c == '{') 
            {
                st.push(c);
            } 
            else 
            {
                if(st.empty()) {
                    valid = false;
                    break;
                }
                char top = st.top();
                if((c == ')' && top == '(') || 
                   (c == ']' && top == '[') || 
                   (c == '}' && top == '{')) {
                    st.pop();
                } else {
                    valid = false;
                    break;
                }
            }
        }
        
        if(!st.empty()) {
            valid = false;
        }
        cout << (valid ? "true" : "false") << endl;
    }
    return 0;
}