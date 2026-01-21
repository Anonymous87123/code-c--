#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int l[N],r[N],a[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    l[1]=a[1];
    for(int i=2;i<=n;i++){
        l[i]=max(a[i],a[i]+l[i-1]); 
    }
    for(int i=2;i<=n;i++){
        l[i]=max(l[i],l[i-1]);
    }
    r[n]=a[n];
    for(int i=n-1;i>=1;i--){
        r[i]=max(a[i],a[i]+r[i+1]);
    }
    for(int i=n-1;i>=1;i--){
        r[i]=max(r[i],r[i+1]); // 从i到n的最大子段和
    }
    int ans=-1e18;
    for(int i=2;i<=n-1;i++){
        ans=max(ans,l[i-1]+r[i+1]);
    }
    cout<<ans<<endl;
    return 0;
}