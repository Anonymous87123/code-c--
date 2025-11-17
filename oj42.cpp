#include<iostream>
using namespace std;
void fmaxmin( double,double ,double ,double& ,double& );
int main()
{
    double a,b,c,max,min;
    cout << "a,b,c=";
    cin >> a >> b >> c;
    fmaxmin( a,b,c,max,min );
    cout << "max=" << max << endl;
    cout << "min=" << min << endl;
}
void fmax( double a,double b,double c,double& max,double& min )
{
    max = a;
    if(b>a)max=b;
    if(c>a)max=c;
}
void fmin( double a,double b,double c,double& max,double& min )
{
    min = a;
    if(b<a)min=b;
    if(c<a)min=c;
}
void fmaxmin( double a,double b,double c,double& max,double& min )
{
    fmax( a,b,c,max,min );
    fmin( a,b,c,max,min );
}
