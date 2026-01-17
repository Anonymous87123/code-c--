#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e8;
const int N = 5005;
int dp[2][N]; // 最长公共子序列长度
int cnt[2][N]; // 方案数
char s1[N], s2[N];
int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    // 去掉末尾的'.'
    s1 = s1.substr(0, s1.find('.'));
    s2 = s2.substr(0, s2.find('.'));
    int n = s1.length();
    int m = s2.length();
    // 初始化
    for (int j = 0; j <= m; j++) {
        cnt[0][j] = 1;
    }
    cnt[1][0] = 1;
    int now = 1, pre = 0;  // 滚动数组指针
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[now][j] = max(dp[pre][j], dp[now][j-1]);
            cnt[now][j] = 0;  // 方案数从0开始累加
            // 如果当前字符相等
            if (s1[i] == s2[j]) {
                dp[now][j] = max(dp[now][j], dp[pre][j-1] + 1);
                if (dp[now][j] == dp[pre][j-1] + 1) {
                    cnt[now][j] = (cnt[now][j] + cnt[pre][j-1]) % MOD;
                }
            }
            
            // 从上方转移
            if (dp[now][j] == dp[pre][j]) {
                cnt[now][j] = (cnt[now][j] + cnt[pre][j]) % MOD;
            }
            
            // 从左方转移
            if (dp[now][j] == dp[now][j-1]) {
                cnt[now][j] = (cnt[now][j] + cnt[now][j-1]) % MOD;
            }
            
            // 去重：如果左上角的长度等于当前长度，说明上方和左方的转移都包含了左上角的方案
            if (s1[i] != s2[j] && dp[pre][j-1] == dp[now][j]) {
                cnt[now][j] = (cnt[now][j] - cnt[pre][j-1] + MOD) % MOD;
            }
        }
        
        // 滚动数组交换
        swap(now, pre);
        
        // 重新初始化当前行的第0列
        cnt[now][0] = 1;
    }
    
    // 最终结果在pre行（因为最后一次交换后，pre指向的是最终结果）
    cout << dp[pre][m] << endl;
    cout << cnt[pre][m] % MOD << endl;
    
    return 0;
}