#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MOD = 100000000;  // 取模值
const int MAXN = 5005;      // 最大长度

int main() {
    // 读取字符串
    string str1, str2;
    cin >> str1 >> str2;
    
    // 去掉末尾的'.'
    int n = str1.size() - 1;  // 第一个字符串有效长度
    int m = str2.size() - 1;  // 第二个字符串有效长度
    
    // 创建滚动数组
    // len1: 上一行的LCS长度
    // len2: 当前行的LCS长度
    // cnt1: 上一行的LCS方案数
    // cnt2: 当前行的LCS方案数
    vector<int> len1(MAXN, 0), len2(MAXN, 0);
    vector<int> cnt1(MAXN, 0), cnt2(MAXN, 0);
    
    // 初始化：空串与任何串的LCS长度为0，方案数为1
    for (int j = 0; j <= m; ++j) {
        cnt1[j] = 1;
    }
    cnt2[0] = 1;  // 每行第一个位置初始化为1
    
    // 动态规划
    for (int i = 1; i <= n; ++i) {
        // 清空当前行
        fill(len2.begin() + 1, len2.begin() + m + 1, 0);
        fill(cnt2.begin() + 1, cnt2.begin() + m + 1, 0);
        for (int j = 1; j <= m; ++j) {
            // 情况1：当前字符匹配
            if (str1[i - 1] == str2[j - 1]) {
                len2[j] = len1[j - 1] + 1;        // 从左上角转移
                cnt2[j] = cnt1[j - 1] % MOD;      // 方案数从左上角继承
            }
            // 情况2：从上边转移
            if (len1[j] > len2[j]) {
                // 上边长度更大，用上边的
                len2[j] = len1[j];
                cnt2[j] = cnt1[j] % MOD;
            } else if (len1[j] == len2[j]) {
                // 长度相等，合并方案数
                cnt2[j] = (cnt2[j] + cnt1[j]) % MOD;
            }
            // 情况3：从左边转移
            if (len2[j - 1] > len2[j]) {
                // 左边长度更大，用左边的
                len2[j] = len2[j - 1];
                cnt2[j] = cnt2[j - 1] % MOD;
            } else if (len2[j - 1] == len2[j]) {
                // 长度相等，合并方案数
                cnt2[j] = (cnt2[j] + cnt2[j - 1]) % MOD;
            }
            
            // 情况4：去重（当字符不匹配且三个方向来源长度相同时）
            if (str1[i - 1] != str2[j - 1] && len1[j - 1] == len2[j]) {
                // 减去重复计算的部分
                cnt2[j] = (cnt2[j] - cnt1[j - 1] + MOD) % MOD;
            }
        }
        
        // 滚动数组：交换当前行和上一行
        swap(len1, len2);
        swap(cnt1, cnt2);
    }
    
    // 输出结果
    cout << len1[m] << endl;      // 最长公共子序列长度
    cout << cnt1[m] % MOD << endl; // 最长公共子序列个数
    
    return 0;
}