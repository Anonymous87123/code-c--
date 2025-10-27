#include <iostream>
using namespace std;

int main() {
    cout << "请你想好一个 1～1000 之内的整数，别告诉我，让我来猜猜！" << endl;
    cout << "猜中了，请输入0；若猜的数小了，请输入-1；若猜的数大了，请输入1" << endl;
    cout << "开始猜了……" << endl;
    
    int low = 1;
    int high = 1000;
    int count = 0;
    int guess;
    int feedback;
    
    while (low <= high) {
        // 计算中间值作为猜测（使用整数除法）
        guess = (low + high-1) / 2;
        count++;
        
        // 输出猜测值
        cout << "是 " << guess << " 吗？" << endl;
        
        // 获取用户反馈
        cin >> feedback;
        
        // 处理用户反馈
        if (feedback == 0) {
            cout << "我猜中啦！只猜了 " << count << " 次，很强吧！" << endl;
            break;
        } else if (feedback == -1) {
            // 猜小了，提高下限
            low = guess + 1;
        } else if (feedback == 1) {
            // 猜大了，降低上限
            high = guess - 1;
        } else {
            // 无效输入处理
            cout << "输入无效，请重新输入 -1、0 或 1" << endl;
            count--; // 不计入无效输入的尝试
        }
    }
    return 0;
}