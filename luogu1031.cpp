//贪心算法
#include <iostream>
using namespace std;
int main() {
    int N;
    cin >> N;
    int a[N];int sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        sum += a[i];
    }
    int average = sum / N;
    int count = 0;
    int balance = 0;  // 当前累积的差值
    for (int i = 0; i < N; i++) {
        // 计算当前堆与平均值的差值
        int diff = a[i] - average;  
        // 如果累积差值不为零，像“欠债”一样累加起来，等到有一个比较大的数弥补
        if (balance != 0) {
            count++;
        }
        // 更新累积差值
        balance += diff;
    }
    cout << count << endl;
    return 0;
}