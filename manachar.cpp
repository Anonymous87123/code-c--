#include<bits/stdc++.h>
define endl '\n'
define int long long
using namespace std;
pair<int,int> manacher(const string& s){
    int n=s.length();
    if(n==0)return {-1,0};
    string t="#";
    for(char c:s){
        t+=c;t+='#';
    }
    int m=t.length();
    vector<int> p(m,0);
    int center=0,right=0;
    for(int i=1;i<m;++i){
        int mirror=2*center-i;
        if(i<right){
            p[i]=min(right-i,p[mirror]);
        }
        int a=i+p[i]+1;int b=i-p[i]-1;
        while(a<m&&b>=0&&t[a]==t[b]){
            ++p[i];++a;--b;
        }
        if(i+p[i]>right){
            center=i;right=i+p[i];
        }
    }
}