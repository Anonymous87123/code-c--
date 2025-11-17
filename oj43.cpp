#include<iostream>
#include<cmath>
using namespace std;
typedef double (*func)(double); 
double trap(func f,double a,double b,int n)
{
    double h = (b-a)/n;
    double sum = 0;
    for(int i = 1; i <= n-1; i++)
    {
        sum += h*f(a+i*h);
    }
    return (h/2)*(f(a)+f(b))+sum;
}
double f1(double x)
{
    return 4.0/(1+pow(x,2));
}
double f2(double x)
{
    return sqrt(1+pow(x,2));
}
int main()
{
    double t1,t2,t3;
    t1 = trap( f1,0,1,10000 ); // 参数分别表示被积函数，a，b，n
    cout << "t1=" << t1 << endl;
    t2 = trap( f2,1,2,10000 );
    cout << "t2=" << t2 << endl;
    t3 = trap( sin,0,3.14159265/2,10000 );
    cout << "t3=" << t3 << endl;
}
