#include<iostream>
#include<iomanip>
using namespace std;
int binary(int n)
{
    if (n == 0) {
        cout << 0;
        return 0;
    } 
    int binary = 0;
    int power = 1; // 当前位的权重
    while (n > 0) {
        int remainder = n % 2;  // 获取当前最低位
        binary += remainder * power;
        power *= 10;            // 下一位的权重
        n /= 2;                 // 去掉已处理的最低位
    } 
    return binary;
}
int main()
{
    cout<<"decimal\tbinary\t\toctal\thexadecimal" << endl;
    for (int i = 1; i <=256; i++)
    {
        cout << dec << i << "\t";
        if(binary(i)>=10000000){
            cout<<binary(i)<<"\t";
        }else{
        cout << binary(i) << "\t\t";}
        cout << oct << i << "\t";
        cout << hex << i << endl;
    }
}