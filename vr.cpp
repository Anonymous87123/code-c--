#include <iostream>
#ifdef _WIN32
#include <windows.h> // 解决Windows中文乱码
#endif
using namespace std;

int main() {
    // 设置控制台编码为UTF-8（Windows系统）
#ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif

    // 游戏提示信息
    cout << "请你想好一个 1～1000 之内的整数，别告诉我，让我来猜猜！" << endl;
    cout << "猜中了，请输入0；若猜的数小了， 请输入-1；若猜的数大了，请输入1" << endl;
    cout << "开始猜了……" << endl;

    int left = 1, right = 1000; // 猜测范围：[left, right]
    int count = 0;              // 猜测次数
    int feedback;               // 玩家反馈（0：猜中，1：猜大，-1：猜小）

    while (true) {
        // 计算中间值：整数除法自动向下取整（符合样例逻辑）
        int mid = (left + right-1) / 2; 
        count++; // 次数加1
        cout << "是 " << mid << " 吗？" << endl;
        cin >> feedback;

        if (feedback == 1) {
            // 猜大了：新范围为[left, mid-1]
            right = mid - 1;
        } else if (feedback == -1) {
            // 猜小了：新范围为[mid+1, right]
            left = mid + 1;
        } else {
            // 猜中，退出循环
            break;
        }
    }

    // 输出结果（含感叹号和换行，严格匹配格式）
    cout << "我猜中啦！只猜了 " << count << " 次，很强吧！" << endl;

    return 0;
}