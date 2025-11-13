#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    double Bposition,va,vb,limit_time;
    cin>>vb>>va>>Bposition>>limit_time;
    double x_a=va*limit_time;
    double x_b=vb*limit_time;
    if(x_b+Bposition>x_a)
    {
        cout<<"·É´¬AÎÞ·¨×·ÉÏ·É´¬B"<<endl;
    }
    else{
        double t=(double(Bposition)/(va-vb));
        if(t>=0&&t<=limit_time)
        {
            cout<<fixed<<setprecision(2)<<t<<endl;
        }
    }
}