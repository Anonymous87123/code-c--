#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int n;cin>>n;
    unordered_map<string,bool>mp;
    unordered_set<string>seen;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        seen.insert(s);
    }
    int m;cin>>m;
    for(int i=0;i<m;i++){
        string s;cin>>s;
        if(seen.find(s)==seen.end())cout<<"WRONG"<<endl;
        else{
            if(mp[s])cout<<"REPEAT"<<endl;
            else{
                cout<<"OK"<<endl;mp[s]=true;//点过了
            }
        }
    }
}