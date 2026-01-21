#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e5+5;
const int INF=1e18;
struct edge{
    int to,cost;
};
vector<edge>graph[MAXN];
int dis[MAXN];
bool vis[MAXN];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,m,start;
    cin>>n>>m>>start;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
    }
    for(int i=1;i<=n;i++)dis[i]=INF;
    dis[start]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    //greater<>比较器会按照pair的第一个元素（距离）进行升序排序
    pq.push({0,start});
    while(!pq.empty()){
        pair<int,int>cur=pq.top();pq.pop();
        int u=cur.second;//节点编号
        if(vis[u])continue;
        vis[u]=true;
        for(auto &edge:graph[u]){
            int v=edge.to,w=edge.cost;
            if(dis[u]+w<dis[v]){
                dis[v]=dis[u]+w;
                pq.push({dis[v],v});
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(dis[i]==INF)cout<<2147483647<<" ";
        else cout<<dis[i]<<" ";
    }
    return 0;
}