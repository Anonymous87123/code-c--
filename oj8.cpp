#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    double x,y;
    while(cin>>x)
    {
        y = double(sinh(1+sinh(x)))/(sinh(2*x)+sinh(3*x));
        cout<< y << endl;
    }
    return 0;
}