#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

double minPay(long long &d, int m) {
    double total_interest = 0.0;
    bool paid_off = false; // 标记是否已还清
    
    for (int i = 1; i <= m; i++) {
        // 如果已还清，后续月份不再计算
        if (paid_off) {
            cout << "月" << i << "最低还款：0" << endl;
            continue;
        }
        
        // 计算月利息
        double monthly_interest = d * 30 * 0.0005; // 日息0.05%，30天
        
        // 累计总利息
        total_interest += monthly_interest;
        
        // 计算含息本金
        double total_amount = d + monthly_interest;
        
        // 计算最低还款额：max(100元, 欠款的10%向上取整)
        double min_payment = max(100.0, ceil(total_amount * 0.1));
        
        // 如果最低还款额超过剩余欠款，则只还剩余部分
        if (min_payment >= total_amount) {
            min_payment = total_amount;
            paid_off = true; // 标记为已还清
        }
        
        // 输出本月最低还款额
        cout << "月" << i << "最低还款：" << static_cast<long long>(min_payment) << endl;
        
        // 更新欠款（四舍五入为整数元）
        double remaining = total_amount - min_payment;
        d = static_cast<long long>(round(remaining));
        
        // 检查是否已还清
        if (d <= 0) {
            paid_off = true;
            d = 0;
        }
    }
    
    return total_interest;
}

int main() {
    long long d;
    int m;
    double ti;
    
    while (cin >> d >> m) {
        ti = minPay(d, m);
        cout << fixed << setprecision(2) << "总利息：" << ti << '\n';
    }
    
    return 0;
}