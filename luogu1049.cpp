//背包问题：有一个箱子容量为 V，同时有 n 个物品，每个物品有一个体积。现在从 n 个物品中，任取若干个装入箱内（也可以不取），使箱子的剩余空间最小。输出这个最小值。输入格式第一行共一个整数 V，表示箱子容量。第二行共一个整数 n，表示物品总数。接下来 n 行，每行有一个正整数，表示第 i 个物品的体积。输出格式共一行一个整数，表示箱子最小剩余空间。
#include <iostream>
using namespace std;
int main()
{
    int V;int n;
    cin >> V >> n;
    vector<int> volumes(n);
    for (int i = 0; i < n; i++)
    {cin>>volumes[i];}   
    // 创建动态规划数组，dp[j]表示容量为j的箱子能装的最大体积
    vector<int> dp(V + 1, 0);//后半部分表示初始化为0
    // 动态规划求解
    for (int i = 0; i < n; i++) {
        // 逆序遍历容量，避免重复放入同一物品
        for (int j = V; j >= volumes[i]; j--) {
            // 状态转移方程：选择放入或不放入当前物品
            dp[j] = max(dp[j], dp[j - volumes[i]] + volumes[i]);
            //中间的等号是赋值号，给出了状态转移方程
        }
    }
    // 最小剩余空间 = 总容量 - 能装的最大体积
    cout << V - dp[V] << endl;
    return 0;
}