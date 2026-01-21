#include<bits/stdc++.h>
#define int long long
using namespace std;

// 定义常量
const int N=1e4+5;  // 最大节点数
const int M=1e5+5;  // 最大边数

// 变量声明
int n,m;           // n:节点数, m:边数
int a[N];          // a[i]:存储节点i的点权
vector<int>g[N];   // g[u]:存储从节点u出发的所有边的终点（原图的邻接表）
vector<int>dag[N]; // dag[i]:存储从SCC i出发的所有SCC的编号（缩点后的DAG）

// Tarjan算法相关变量(SCC 是 Strongly Connected Component​ 的缩写，中文翻译为强连通分量)
int dfn[N];        // dfn[u]:节点u的深度优先搜索序号（时间戳）
int low[N];        // low[u]:从u出发能回溯到的最早的祖先节点的dfn值，通过比较dfn[u]和low[u]来判断是否发现SCC
int scc_id[N];     // scc_id[u]:节点u所属的强连通分量编号
int scc_sum[N];    // scc_sum[i]:第i个强连通分量的总点权
int scc_cnt;       // 强连通分量计数器
int stamp;         // 时间戳计数器

// 栈相关变量
int stk[N];        // 栈，用于存储当前搜索路径上的节点
int top;           // 栈顶指针
bool in_stk[N];    // in_stk[u]:标记节点u是否在栈中

// 动态规划相关
int dp[N];         // dp[i]:从第i个强连通分量出发能获得的最大点权和

// Tarjan算法实现
void tarjan(int u){
    dfn[u]=low[u]=++stamp;// 初始化当前节点的dfn和low值
    stk[++top]=u;// 当前节点入栈
    in_stk[u]=true;//标记节点在栈中
    for(int v:g[u]){//通过访问main函数存储的邻接表来访问每个邻居
        if(!dfn[v]){  // 如果邻居v未被访问过
            tarjan(v);  // 递归访问v
            low[u]=min(low[u],low[v]); 
            // 更新u能回溯到的最小dfn，回溯时更新low[u]为low[u]和low[v]的最小值。原因：节点 v未被访问，因此需要先递归调用 tarjan(v)完成对 v的深度搜索。递归返回后，low[v]已经计算完成，表示从 v出发能回溯到的最早节点的时间戳。
            //更新逻辑：由于 u到 v有一条边，如果 v能回溯到更早的节点（即 low[v]较小），那么 u也可能通过 v回溯到那个节点。因此，用 low[v]更新 low[u]，确保 low[u]反映整个子树（包括 v）的回溯能力。
            //类比：这类似于“子节点能追溯到多早，父节点也能追溯到多早”。
        }else if(in_stk[v]){  // 如果v已被访问且在栈中
            low[u]=min(low[u],dfn[v]);  
            // 更新u能回溯到的最小dfn，原因：节点 v已被访问且仍在栈中，说明 v是当前DFS路径上的一个祖先节点（或同一路径上的节点），此时边 u → v是一条后向边（back edge）。
            //更新逻辑：后向边允许 u直接回溯到 v，而 v的dfn值（dfn[v]）通常小于 u的dfn值（因为 v先被访问）。因此，用 dfn[v]更新 low[u]，表示 u能通过这条后向边直接回溯到 v的时间戳。
            //为什么不用 low[v]：如果使用 low[v]，可能会错误地将 u回溯到更早的节点，因为 v可能已经属于另一个强连通分量（SCC），但 v仍在栈中，说明它还在当前SCC的考虑范围内。使用 dfn[v]更安全，只考虑直接后向边，避免跨SCC的错误回溯。
        }
    }
    // 如果u是当前强连通分量的根节点
    if(dfn[u]==low[u]){
        ++scc_cnt;  // 新增一个强连通分量
        int y;
        // 弹出栈中元素，直到遇到u
        do{
            y=stk[top--];        // 弹出栈顶元素
            in_stk[y]=false;     // 标记不在栈中
            scc_id[y]=scc_cnt;   // 标记y属于当前SCC
            scc_sum[scc_cnt]+=a[y];  // 累加SCC的点权和
        }while(y!=u);  // 直到弹出u为止
    }
}

// 在DAG上进行记忆化搜索
int dfs(int u_scc){
    // 如果已经计算过，直接返回结果
    if(dp[u_scc]!=-1)return dp[u_scc];
    
    // 至少包含当前SCC的点权
    dp[u_scc]=scc_sum[u_scc];
    int max_next=0;
    
    // 遍历所有后继SCC
    for(int v_scc:dag[u_scc]){
        // 找到最大的后继路径
        max_next=max(max_next,dfs(v_scc));
    }
    
    // 当前SCC的点权加上最大后继路径
    dp[u_scc]+=max_next;
    return dp[u_scc];
}

signed main(){
    // 加速输入输出
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    
    // 输入节点数和边数
    cin>>n>>m;
    
    // 输入每个节点的点权
    for(int i=1;i<=n;i++)cin>>a[i];
    
    // 输入图的边信息
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);  // 添加有向边u->v
    }
    
    // 初始化Tarjan算法相关变量
    stamp=0;
    top=0;
    scc_cnt=0;
    
    // 对每个未访问的节点执行Tarjan算法
    for(int i=1;i<=n;i++){
        if(!dfn[i])tarjan(i);
    }
    
    // 构建缩点后的DAG
    for(int u=1;u<=n;u++){
        for(int v:g[u]){
            int u_scc=scc_id[u];  // u所在的SCC编号
            int v_scc=scc_id[v];  // v所在的SCC编号
            if(u_scc!=v_scc){     // 如果u和v不在同一个SCC
                dag[u_scc].push_back(v_scc);  // 在SCC之间添加边
            }
        }
    }
    
    // 初始化DP数组为-1（表示未计算）
    memset(dp,-1,sizeof(dp));
    int ans=0;
    
    // 对每个SCC进行记忆化搜索，找到最大点权和
    for(int i=1;i<=scc_cnt;i++){
        ans=max(ans,dfs(i));
    }
    
    // 输出结果
    cout<<ans<<endl;
    return 0;
}