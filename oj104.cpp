#include<bits/stdc++.h>
using namespace std;
//template
int main(){
    int n;
    while(cin>>n){
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int x;
    cin>>x;
    auto it=find(a.begin(),a.end(),x);
    if(it!=a.end())cout<<*it-1<<endl;
    else cout<<-1<<endl;}
}