#include <iostream>
#include <iomanip>
using namespace std;
int binary(int n)
{
    int count=1;
    int sup=1;
    int binary=0;
    while(sup<=n)
    {
        sup*=2;
        count++;
    }
    while(n>1)
    {
        if(n%2==1)
        {
            n=n/2;binary+=1*pow(10,count-1);
            count--;
        }
        if(n%2==1)
        {
            n=n/2;count--;
        }
    }
}
int main() {
    // 输出表头
    cout << "decimal\t\tbinary\t\t\toctal\thexadecimal" << endl;
    
    for (int i = 1; i <= 256; ++i) {
        // 输出十进制
        cout << dec << i << "\t\t";
        
        // 输出二进制（使用bitset）
        cout << bitset<8>(i) << "\t\t";
        
        // 输出八进制
        cout << oct << i << "\t";
        
        // 输出十六进制
        cout << hex << uppercase << i << endl;
        
        // 恢复十进制输出
        cout << dec;
    }
    
    return 0;
}