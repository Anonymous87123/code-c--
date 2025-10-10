#include<iostream>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        if(n<100000||n>999999){cout<<"输入错误"<<endl;break;}
        int a[6];
        a[0]=n/100000;
        a[1]=(n%100000)/10000;
        a[2]=(n%10000)/1000;
        a[3]=(n%1000)/100;
        a[4]=(n%100)/10;
        a[5]=n%10;
        for (int i = 0; i < 6; i++){
            a[i]+=7;
            a[i]=a[i]%10;
        }
        cout<<a[5]<<a[4]<<a[3]<<a[2]<<a[1]<<a[0]<<endl;
    }
    return 0;
}