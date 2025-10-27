#include <iostream>
using namespace std;
int n; // 字典序长度
int m; // 目标位置
int count = 0; // 当前计数
int result = 0; // 存储结果
// 深度优先搜索生成字典序
void search(long long cur, int depth) {
    // 终止条件：超过n或已找到结果
    if (cur > n || result != 0) return;
    // 当前数字有效，计数增加
    count++;
    // 找到第m个数字
    if (count == m) {
        result = cur;
        return;
    }
    // 递归生成子节点（0-9）
    for (int i = 0; i <= 9; i++) {
        long long next = cur * 10 + i;
        if (next > n) break; // 超过n则终止
        search(next, depth + 1);
    }
}
int main() {
    while (cin >> n >> m) {
        // 重置状态变量
        count = 0;
        result = 0;
        
        // 从1-9开始生成（避免前导零）
        for (int i = 1; i <= 9; i++) {
            if (result != 0) break; // 已找到结果
            search(i, 1);
        }
        
        cout << result << endl;
    }
    return 0;
}