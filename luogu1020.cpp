#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> heights;
    string line;
    // 读取一行输入
    getline(cin, line);
    stringstream ss(line);
    int h;
    while (ss >> h) {
        heights.push_back(h);
    }
    int n = heights.size();
    if (n == 0) {
        cout<<0<<endl;
        cout<<0<<endl;
        return 0;
    }
    // 第一问：求最长不上升子序列的长度
    vector<int> dp;  // dp[i] 表示长度为i的不上升子序列的最小结尾值
    for (int i = 0; i < n; i++) {
        // 在dp中找到第一个小于heights[i]的位置
        auto it = upper_bound(dp.begin(), dp.end(), heights[i], greater<int>());
        if (it == dp.end()) {
            dp.push_back(heights[i]);  // 没有找到，延长序列
        } else {
            *it = heights[i];  // 替换掉第一个小于heights[i]的元素
        }
    }
    int ans1 = dp.size();
    // 第二问：求最少能划分成多少个不上升子序列 = 最长上升子序列的长度
    vector<int> lis;  // lis[i] 表示长度为i+1的上升子序列的最小结尾值
    for (int i = 0; i < n; i++) {
        // 在lis中找到第一个大于等于heights[i]的位置
        auto it = lower_bound(lis.begin(), lis.end(), heights[i]);
        if (it == lis.end()) {
            lis.push_back(heights[i]);  // 没有找到，延长序列
        } else {
            *it = heights[i];  // 替换掉第一个大于等于heights[i]的元素
        }
    }
    int ans2 = lis.size();
    cout << ans1 << "\n" << ans2 << "\n";
    return 0;
}