#include<bits/stdc++.h>
#define int long long
using namespace std;
int d(int x){
    int ans=0;
    while(x>0){
        int temp=x%10;
        ans+=temp;
        x-=temp;
        x/=10;
    }
    return ans;
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        int ans=0;
        for(int i=1;i<=90;++i){
            int y=x+i;
            if(d(y)==i){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
}