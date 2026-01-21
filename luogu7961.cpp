#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int N=35;
const int M=105;
int v[M];
int C[N][N];
int powv[M][N];
int dp[2][N][N][N];
int popcnt(int x){
    int cnt=0;
    while(x){
        cnt += (x&1);
        x >>= 1;
    }
    return cnt;
}
signed main(){
    for(int i=0;i<N;i++){
        C[i][0]=1;
        for(int j=1;j<=i;j++){
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
        }
    }
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<=m;i++) cin>>v[i];
    for(int i=0;i<=m;i++){
        powv[i][0]=1;
        for(int t=1;t<=n;t++){
            powv[i][t]=powv[i][t-1]*v[i]%mod;
        }
    }
    memset(dp,0,sizeof(dp));
    dp[0][0][0][0]=1;
    for(int i=0;i<=m;i++){
        int cur=i&1, nxt=cur^1;
        for(int j=0;j<=n;j++)
            for(int c=0;c<=n;c++)
                for(int b=0;b<=n;b++)
                    dp[nxt][j][c][b]=0;
        for(int j=0;j<=n;j++){
            for(int c=0;c<=n;c++){
                for(int b=0;b<=n;b++){
                    if(dp[cur][j][c][b]==0) continue;
                    for(int t=0;t<=n-j;t++){
                        int newc=(c+t)/2;
                        int bit=(c+t)%2;
                        int newb=b+bit;
                        if(newb>n)continue;
                        dp[nxt][j+t][newc][newb]=(dp[nxt][j+t][newc][newb]+dp[cur][j][c][b]*C[n-j][t]%mod*powv[i][t])% mod;
                    }
                }
            }
        }
    }
    int ans=0;
    int final=(m+1)&1;
    for(int c=0;c<=n;c++){
        for(int b=0;b<=n;b++){
            if(b+popcnt(c)<=k){
                ans=(ans+dp[final][n][c][b])%mod;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}