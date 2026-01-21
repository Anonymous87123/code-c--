#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1000000007;
const int N=1005;
const int M=205;
const int K=205;
int dp[2][M][K];int dp1[2][M][K];
signed main(){
    int n,m,k;
    cin>>n>>m>>k;
    char a[N];
    char b[M];
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)cin>>b[i];
    int cur=0;int pre=1;
    dp[pre][0][0]=1;
    for(int i=1;i<=n;i++){
        memset(dp[cur],0,sizeof(dp[cur]));
        memset(dp1[cur],0,sizeof(dp1[cur]));
        for(int j=0;j<=m;j++){
            for(int t=0;t<=k;t++){
                if(j>=1&&t>=1&&a[i]==b[j]){
                    dp1[cur][j][t]=(dp1[pre][j-1][t]+dp[pre][j-1][t-1])%MOD;
                }else{
                    dp1[cur][j][t]=0;
                }
                dp[cur][j][t]=(dp[pre][j][t]+dp1[cur][j][t])%MOD;
            }
        }
        swap(cur, pre);
    }
    cout<<dp[cur][m][k]<<endl;
    return 0;
}