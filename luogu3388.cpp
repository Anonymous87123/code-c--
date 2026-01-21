#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e4+5;
const int M=1e5+5;
vector<int> g[N];
int dfn[N],low[N],timer=0;
bool cut[N];
int n,m;
void tarjan(int u,int fa){
    dfn[u]=low[u]=++timer;
    int child=0;
    for(int v:g[u]){
        if(dfn[v]==0){
            tarjan(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>=dfn[u]){
                cut[u]=true;
            }
            child++;
        }else if(v!=fa){
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(fa==-1&&child>1){
        cut[u]=true;
    }
}
signed main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(dfn[i]==0){
            tarjan(i,-1);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(cut[i]){
            ans++;
        }
    }
    cout<<ans<<endl;
    bool first=true;
    for(int i=1;i<=n;i++){
        if(cut[i]){
            if(first==false){
                cout<<" ";
            }
            cout<<i;
            first=false;
        }
    }
    if(ans > 0) cout << endl;
    return 0;
}