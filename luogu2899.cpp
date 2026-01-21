#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e4+5;
const int INF=1e9;
int N;
int dp[MAXN][3];
vector<int> tree[MAXN];
void dfs(int u,int dad){
    dp[u][0]=1;
    bool leaf=true;
    int sum2=0;
    bool flag=false;
    int min_diff=INF; 
    for (int v:tree[u]){
        if(v==dad)continue;
        leaf=false;
        dfs(v,u);
        dp[u][0]+=min(dp[v][0],min(dp[v][1], dp[v][2]));
        int m=min(dp[v][0],dp[v][2]);
        sum2+=m;
        if(dp[v][0]<=dp[v][2]){
            flag=true;
        }else{
            min_diff=min(min_diff,dp[v][0]-dp[v][2]);
        }
    }
    if (leaf) {
        dp[u][1]=0;
        dp[u][2]=INF;
    } else {
        dp[u][1]=sum2;
        if (flag) {
            dp[u][2]=sum2;
        } else {
            dp[u][2]=sum2+min_diff;
        }
    }
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>N;
    for(int i=1;i<N;i++){
        int a,b;cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(1,0);
    cout<<min(dp[1][0],dp[1][2])<<endl;
    return 0;
}