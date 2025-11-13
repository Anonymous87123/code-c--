#include <iostream>
using namespace std;

bool is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main() {
    const int base_year = 2024;
    
    int n;
    while (cin >> n) {
        // 处理n<=7的情况（10月内）
        if (n <= 7) {
            int day = 24 + n;
            cout << "2024年10月" << day << "日";
        } 
        // 处理n>7的情况
        else {
            int s = n - 7;  // 10月24日+7天=10月31日，s是从11月1日开始的天数
            int current_year = base_year;
            int current_month = 11;  // 从11月开始计算
            
            // 循环减去各月份的天数
            while (s > 0) {
                int days_in_month;
                
                // 计算当前月份天数
                if (current_month == 2) {
                    days_in_month = is_leap_year(current_year) ? 29 : 28;
                } else if (current_month == 4 || current_month == 6 || 
                           current_month == 9 || current_month == 11) {
                    days_in_month = 30;
                } else {
                    days_in_month = 31;
                }
                
                // 如果剩余天数大于本月天数，减去本月天数
                if (s > days_in_month) {
                    s -= days_in_month;
                    current_month++;
                    
                    // 年份进位处理
                    if (current_month > 12) {
                        current_month = 1;
                        current_year++;
                    }
                } else {
                    break;  // 剩余天数在本月内
                }
            }
            cout << current_year << "年" << current_month << "月" << s << "日";
        }
        
        // 计算星期几
        int m = n % 7;
        if (m == 0) cout << "星期四";
        else if (m == 1) cout << "星期五";
        else if (m == 2) cout << "星期六";
        else if (m == 3) cout << "星期日";
        else if (m == 4) cout << "星期一";
        else if (m == 5) cout << "星期二";
        else if (m == 6) cout << "星期三";
        cout << endl;
    }
    return 0;
}