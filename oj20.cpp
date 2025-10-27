#include <iostream>
using namespace std;

int main() {
    int low = 1;
    int high = 1000;
    int guess;
    int feedback;
    
    while (true) {
        // 计算中间值作为猜测
        guess = (low + high) / 2;
        cout << guess << endl;
        
        // 获取用户反馈
        cin >> feedback;
        
        // 根据反馈调整搜索范围
        if (feedback == 1) {
            // 猜大了，调整上限
            high = guess - 1;
        } else if (feedback == -1) {
            // 猜小了，调整下限
            low = guess + 1;
        } else if (feedback == 0) {
            // 猜对了，结束游戏
            break;
        }
        
        // 检查是否还有可猜的数
        if (low > high) {
            // 理论上不应该发生，表示用户反馈有误
            cout << "Error: no valid numbers left!" << endl;
            break;
        }
    }
    
    return 0;
}