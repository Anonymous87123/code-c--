/*
# P1352 没有上司的舞会
## 题目描述
某大学有 $n$ 个职员，编号为 $1\ldots n$。
他们之间有从属关系，也就是说他们的关系就像一棵以校长为根的树，父结点就是子结点的直接上司。
现在有个周年庆宴会，宴会每邀请来一个职员都会增加一定的快乐指数 $r_i$，但是呢，如果某个职员的直接上司来参加舞会了，那么这个职员就无论如何也不肯来参加舞会了。
所以，请你编程计算，邀请哪些职员可以使快乐指数最大，求最大的快乐指数。
## 输入格式
输入的第一行是一个整数 $n$。
第 $2$ 到第 $(n + 1)$ 行，每行一个整数，第 $(i+1)$ 行的整数表示 $i$ 号职员的快乐指数 $r_i$。
第 $(n + 2)$ 到第 $2n$ 行，每行输入一对整数 $l, k$，代表 $k$ 是 $l$ 的直接上司。
## 输出格式
输出一行一个整数代表最大的快乐指数。
## 输入输出样例 #1
### 输入 #1
```
7
1
1
1
1
1
1
1
1 3
2 3
6 4
7 4
4 5
3 5

```
### 输出 #1

```
5

``
## 说明/提示
#### 数据规模与约定
对于 $100\%$ 的数据，保证 $1\leq n \leq 6 \times 10^3$，$-128 \leq r_i\leq 127$，$1 \leq l, k \leq n$，且给出的关系一定是一棵树。
*/
//这道题是一个经典的树形DP问题。我们需要在树形结构上做决策，每个节点有选和不选两种状态，且父子节点不能同时被选。
//dp[u][0]：以节点u为根的子树，u不参加舞会时，该子树的最大快乐指数
//dp[u][1]：以节点u为根的子树，u参加舞会时，该子树的最大快乐指数
//状态转移
//如果u不参加：dp[u][0] = ∑ max(dp[v][0], dp[v][1])，其中v是u的子节点
//如果u参加：dp[u][1] = happy[u] + ∑ dp[v][0]，其中v是u的子节点
//最终答案：max(dp[root][0], dp[root][1])
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 6005;
vector<int> son[MAXN];  // 邻接表存储子节点
int happy[MAXN]; // 快乐指数
int dp[MAXN][2]; // dp数组
int indeg[MAXN]; // 入度，用于找根节点
void dfs(int u) {
    dp[u][1] = happy[u];// 初始化dp[u][1]为u的快乐指数
    // 遍历所有子节点
    for (int v : son[u]) {
        dfs(v);
        // u不参加，子节点可以参加或不参加
        dp[u][0] += max(dp[v][0], dp[v][1]);
        // u参加，子节点不能参加
        dp[u][1] += dp[v][0];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> happy[i];
    }
    // 读入从属关系(邻接表)
    for (int i = 1; i < n; i++) {  // 树有n-1条边
        int l, k;
        cin >> l >> k;
        son[k].push_back(l);
        indeg[l]++;  // l有一个上司
    }
    int root = 0;
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) {
            root = i;//找到根
            break;
        }
    }
    dfs(root);// 从根节点开始DFS
    cout << max(dp[root][0], dp[root][1]) << endl;
    return 0;
}