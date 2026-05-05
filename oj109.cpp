#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    while(getline(cin,s)){
        vector<int>a;
        for(int i=0;i<s.length();i++){
            if(isdigit(s[i])){
                if(s[i-1]!='-'){
                    a.push_back(s[i]-'0');
                }else if(s[i-1]=='-'){
                    a.push_back(-(s[i]-'0'));
                }
            }           
        }
        for(int i=0;i<a.size();i++){
            bool flag=true;
            for(int j=0;j<a.size()-i-1;j++){
                if(a[j]==a[i])flag=false;
            }
            if(flag)cout<<a[i]<<" ";
        }
        cout<<endl;
    }
}
