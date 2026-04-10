#include<bits/stdc++.h>
using namespace std;
int main() {
    int a1,a2,a3;
    int b1,b2,b3;
    double c;
    cin>>a1>>a2>>a3;
    cin>>b1>>b2>>b3;
    cin>>c;
    double a=a1+a2*0.1+a3*0.01;
    double b=b1+b2*0.1+b3*0.01;
    cout<<fixed<<setprecision(2)<<a+c<<endl;
    cout<<fixed<<setprecision(2)<<b-a<<endl;
    cout<<fixed<<setprecision(2)<<a+2.18<<endl;
}