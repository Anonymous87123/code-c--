#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e4+5;
const int MAXK=1e3+5;
int skill[MAXN];
int dp[MAXN];
signed main() {
    int N,K;cin>>N>>K;
    for(int i=1;i<=N;i++)cin>>skill[i];
    dp[1]=skill[1];
    for(int i=2;i<=N;i++){
        int mx=0;
        for(int j=1;j<=K&&j<=i;j++){
            mx=max(mx,skill[i-j+1]);
            dp[i]=max(dp[i],dp[i-j]+mx*j);
        }
    }
    cout<<dp[N]<<endl;
    return 0;
}