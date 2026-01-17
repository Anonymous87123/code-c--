/*
# P1064 [NOIP 2006 提高组] 金明的预算方案
## 题目描述
金明今天很开心，家里购置的新房就要领钥匙了，新房里有一间金明自己专用的很宽敞的房间。更让他高兴的是，妈妈昨天对他说：“你的房间需要购买哪些物品，怎么布置，你说了算，只要不超过 $n$ 元钱就行”。今天一早，金明就开始做预算了，他把想买的物品分为两类：主件与附件，附件是从属于某个主件的，下表就是一些主件与附件的例子：
| 主件 | 附件 |
| :----------: | :----------: |
| 电脑 | 打印机，扫描仪 |
| 书柜 | 图书 |
| 书桌 | 台灯，文具 |
| 工作椅 | 无 |
如果要买归类为附件的物品，必须先买该附件所属的主件。每个主件可以有 $0$ 个、$1$ 个或 $2$ 个附件。每个附件对应一个主件，附件不再有从属于自己的附件。金明想买的东西很多，肯定会超过妈妈限定的 $n$ 元。于是，他把每件物品规定了一个重要度，分为 $5$ 等：用整数 $1 \sim 5$ 表示，第 $5$ 等最重要。他还从因特网上查到了每件物品的价格（都是 $10$ 元的整数倍）。他希望在不超过 $n$ 元的前提下，使每件物品的价格与重要度的乘积的总和最大。
设第 $j$ 件物品的价格为 $v_j$，重要度为 $w_j$，共选中了 $k$ 件物品，编号依次为 $j_1,j_2,\dots,j_k$，则所求的总和为：
$$v_{j_1} \times w_{j_1}+v_{j_2} \times w_{j_2}+ \dots +v_{j_k} \times w_{j_k}$$
请你帮助金明设计一个满足要求的购物单。
## 输入格式
第一行有两个整数，分别表示总钱数 $n$ 和希望购买的物品个数 $m$。
第 $2$ 到第 $(m + 1)$ 行，每行三个整数，第 $(i + 1)$ 行的整数 $v_i$，$p_i$，$main_i$ 分别表示第 $i$ 件物品的价格、重要度以及它对应的的主件。如果 $main_i=0$，表示该物品本身是主件。
## 输出格式
输出一行一个整数表示答案。
## 输入输出样例 #1
## 输入 #1
```
1000 5
800 2 0
400 5 1
300 5 1
400 3 0
500 2 0
```
## 输出 #1
```
2200
```
## 说明/提示
#### 数据规模与约定
对于全部的测试点，保证 $1 \lemain n \lemain 3.2 \times 10^4$，$1 \lemain m \lemain 60$，$0 \lemain v_i \lemain 10^4$，$1 \lemain p_i \lemain 5$，$0 \lemain main_i \lemain m$，答案不超过 $2 \times 10^5$。
NOIP 2006 提高组 第二题
*/

/*
这道题是典型的有依赖的背包问题，可以将每个主件及其附件看作一组，每组内包含多种组合（主件、主件+附件1、主件+附件2、主件+附件1+附件2），然后使用分组背包求解。
解题步骤：
读入总钱数 n和物品数 m
用数组记录每个主件的附件，每个主件最多有两个附件。
遍历所有主件（main[i] == 0），为每个主件生成所有可能的组合，包括：
仅主件
主件 + 附件1（如果存在）
主件 + 附件2（如果存在）
主件 + 附件1 + 附件2（如果两个附件都存在）
每个组合记录总价格和总价值（价格 × 重要度）。
使用分组背包的动态规划求解：
dp[j]表示总花费不超过 j时的最大价值。
遍历每个主件组，对于每组，从容量的最大值到0遍历，再遍历该组内的每个组合，用 dp[j - cost] + val更新 dp[j]。
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;//n是钱，m是物品数
    cin >> n >> m;
    vector<int> price(m + 1), prior(m + 1), main(m + 1);// 价格，重要度，主件编号
    vector<vector<int>> relation(m + 1);//存储长短不一的邻接表，而不一定是完完整整的二维数组
    for (int i = 1; i <= m; i++) {
        cin >> price[i] >> prior[i] >> main[i];
        prior[i] = price[i] * prior[i];  // 直接存储价值
        if (main[i] != 0) //表示该物品是附件，main[i]是对应主件的编号（输入顺序编号）
        {
            relation[main[i]].push_back(i);
        }
    }
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= m; i++) {
        if (main[i] != 0) continue;  // 跳过附件
        int main_price = price[i];
        int main_value = prior[i];
        vector<pair<int, int>> cases;
        // 情况1: 只买主件
        if (main_price <= n) {
            cases.push_back({main_price, main_value});
        }
        // 如有附件
        if (!relation[i].empty()) {
            int a1 = relation[i][0];
            // 情况2: 主件 + 附件1
            int v2 = main_price + price[a1];
            int val2 = main_value + prior[a1];
            if (v2 <= n) {
                cases.push_back({v2, val2});
            }
            // 如果有第二个附件
            if (relation[i].size() > 1) {
                int a2 = relation[i][1];
                // 情况3: 主件 + 附件2
                int v3 = main_price + price[a2];
                int val3 = main_value + prior[a2];
                if (v3 <= n) {
                    cases.push_back({v3, val3});
                }
                // 情况4: 主件 + 附件1 + 附件2
                int v4 = main_price + price[a1] + price[a2];
                int val4 = main_value + prior[a1] + prior[a2];
                if (v4 <= n) {
                    cases.push_back({v4, val4});
                }
            }
        }
        // 分组背包
        for (int j = n; j >= 0; j--) {
            for (auto& c : cases) {
                if (j >= c.first) {
                    dp[j] = max(dp[j], dp[j - c.first] + c.second);
                }
            }
        }
    }
    cout << dp[n] << endl;
    return 0;
}