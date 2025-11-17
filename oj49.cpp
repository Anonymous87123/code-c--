#include<bits/stdc++.h>
using namespace std;
double minPay(long long &d, int m)
{
    double ti=0;
    for(int i=1;i<=m;i++)
    {
        cout<<"月"<<i<<"最低还款：";
        ti+=double(d*30)/2000;
        d+=round(double(d*30)/2000);
        long long k = max(100.0,ceil(double(d)/10));
        cout<<k<<endl;
        d-=k;
    }
    return ti;
}
int main()
{
    long long d;
    int m;
    double ti;
    while(cin>>d>>m)
    {
        ti=minPay(d,m);
        cout<<fixed<<setprecision(2) << "总利息：" <<ti<<endl;
    }
    return 0;
}