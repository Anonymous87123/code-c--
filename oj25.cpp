#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    double height,m;
    cin>>height>>m;
    int times=1;
    const double m_0 = m;
    double sum_bounce=height;
    if(height*m<0.1)
    {
        cout<<fixed<<setprecision(2)<<height+height*m<<endl;
        cout<<2<<endl;return 0;
    }
    while(height*(m)>=0.1)
    {
        times++;
        sum_bounce+=(height*(m));
        m*=m_0;
    }
    cout<<fixed<<setprecision(2)<<sum_bounce+(height*(m))<<endl;
    cout<<times+1<<endl;
}