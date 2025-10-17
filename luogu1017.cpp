#include <iostream>
using namespace std;
int n, base; // n: 十进制数, m: 目标进制基数（可以是负数）
char a[100001]; // 存储转换结果的字符数组
int l = 0; // 结果数组的长度

int main() {
    int i;
    cin >> n >> base; // 输入十进制数和目标进制基数
    cout << n << "="; // 输出转换前的数
    
    while (n != 0) {
        int j = n % base; // 计算余数
        n /= base; // 更新n为商
        // 关键处理：当余数为负数时的调整
        if (j < 0) {
            j -= base; // 余数调整为正数
            n++;    // 商加1补偿（因为是负数进制）
        }
        // 将余数转换为字符
        if (j < 10)
            a[++l] = (char)(j + 48); // 0-9转换为数字字符
        else
            a[++l] = (char)((j - 10) + 'A'); // 10-35转换为字母
    }
    // 倒序输出结果（进制转换需要逆序）
    for (i = l; i >= 1; i--)
        cout << a[i];
    cout << "(base" << base << ")" << endl; // 输出目标进制
}