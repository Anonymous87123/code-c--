#include <iostream>
using namespace std;
typedef void (*orderFun)(int &, int &, int &);
void sequence(int &a, int &b, int &c);
void retrograde(int &a, int &b, int &c);
int main()
{
    int a, b, c;
    int t1, t2, t3;
    orderFun pf; // 说明函数指针

    cout << "请输入三个不相等的整数：";
    cin >> a >> b >> c;

    t1 = a; t2 = b; t3 = c;
    pf = sequence; // 获取函数地址
    pf(t1, t2, t3); // 调用函数
    cout << "顺序输出：" << t1 << " " << t2 << " " << t3 << endl;

    t1 = a; t2 = b; t3 = c;
    pf = retrograde; // 获取函数地址
    pf(t1, t2, t3); // 调用函数
    cout << "逆序输出：" << t1 << " " << t2 << " " << t3 << endl;

    return 0;
}

// 定义sequence函数：按升序排列三个整数
void sequence(int &a, int &b, int &c)
{
    if (a > b) swap(a, b);
    if (a > c) swap(a, c);
    if (b > c) swap(b, c);
}

// 定义retrograde函数：按降序排列三个整数
void retrograde(int &a, int &b, int &c)
{
    if (a < b) swap(a, b);
    if (a < c) swap(a, c);
    if (b < c) swap(b, c);
}