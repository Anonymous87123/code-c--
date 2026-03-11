#include<bits/stdc++.h>
using namespace std;
int root(int &x){
    while(x%2==0)x/=2;
    return x;
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;vector<int> a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        bool ok=true;
        for(int i=0;i<n;i++){
            int pos=i+1;
            if(root(pos)!=root(a[i])){
                ok=false;break;
            }
        }
        cout<<(ok?"YES":"NO")<<endl;
    }
}