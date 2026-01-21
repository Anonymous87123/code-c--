#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    int N,M;
    cin>>N>>M;
    int score[355];
    for(int i=1;i<=N;i++)cin>>score[i];
    int cnt[5]={0};
    for(int i=1;i<=M;i++){
        int b;
        cin>>b;
        cnt[b]++;
    }
    int dp[41][41][41][41];
    memset(dp, -1, sizeof(dp));
    dp[0][0][0][0]=score[1];
    for(int a=0;a<=cnt[1];a++){
        for(int b=0;b<=cnt[2];b++){
            for(int c=0;c<=cnt[3];c++){
                for(int d=0;d<=cnt[4];d++){
                    if(a==0&&b==0&&c==0&&d==0)continue;
                    int pos=a+b*2+c*3+d*4+1;
                    if(pos>N)continue;
                    if(a>0&&dp[a-1][b][c][d]!=-1)dp[a][b][c][d]=max(dp[a][b][c][d],dp[a-1][b][c][d]+score[pos]);
                    if(b>0&&dp[a][b-1][c][d]!=-1)dp[a][b][c][d]=max(dp[a][b][c][d],dp[a][b-1][c][d]+score[pos]);
                    if(c>0&&dp[a][b][c-1][d]!=-1)dp[a][b][c][d]=max(dp[a][b][c][d],dp[a][b][c-1][d]+score[pos]);
                    if(d>0&&dp[a][b][c][d-1]!=-1)dp[a][b][c][d]=max(dp[a][b][c][d],dp[a][b][c][d-1]+score[pos]);
                }
            }
        }
    }
    cout<<dp[cnt[1]][cnt[2]][cnt[3]][cnt[4]]<<endl;
}