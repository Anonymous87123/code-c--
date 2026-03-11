#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    string s;
    cin>>s;
    int n=s.size();
    vector<int>pi(n,0);
    for(int i=1;i<n;i++){
        int j=pi[i-1];
        while(j>0&&s[i]!=s[j]) j=pi[j-1];
        if(s[i]==s[j]) j++;
        pi[i]=j;
    }
    vector<int>borders;
    int len=n;
    while(len>0){
        borders.push_back(len);
        len=pi[len-1];
    }
    reverse(borders.begin(),borders.end());
    vector<int>ans(n+1,0);
    for(int i=0;i<n;++i)ans[pi[i]]++;
    ans[n]=1;
    for(int i=n;i>=1;--i)ans[pi[i-1]]+=ans[i];
    cout<<borders.size()<<endl;
    for(int l:borders)cout<<l<<" "<<ans[l]<<endl;
}

