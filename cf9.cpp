#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;vector<int>a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        if(n==1){cout<<0<<endl;continue;}
        const int INF=1e9;
        vector<int>dp(6,INF);
        for(int v=1;v<=6;v++){
            dp[v-1]=(a[0]!=v);
        }
        for(int i=1;i<n;i++){
            vector<int>dp2(6,INF);
            for(int v=1;v<=6;v++){
                int cost=(a[i]!=v);
                for(int u=1;u<=6;u++){
                    if(u==v&&u+v==7)continue;
                    dp2[v-1]=min(dp2[v-1],dp[u-1]+cost);
                }
            }
            dp=move(dp2);
        }
        int ans=*min_element(dp.begin(),dp.end());
        cout<<ans<<endl;
    }
}