#include<bits/stdc++.h>
using namespace std;
template<class T>
class fuck{};
int main(){
    string s;
    int a[26]={0};
    while(getline(cin,s)){
        int len=s.length();string rank="";
        for(int i=0;i<len;i++){
            int temp=s[i]-'a';
            if(a[temp]==0){
                rank+=s[i];
            }
            a[temp]++;
        }
        for(char c:rank){
            int m=c-'a';
            cout<<c<<":"<<a[m]<<" ";
        }
        cout<<endl;
    }
}