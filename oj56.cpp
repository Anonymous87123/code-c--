#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    double a,b,c,d;
    while(cin>>s>>a>>b>>c>>d)
    {
        if(s=="+")
        {
            cout<<fixed<<setprecision(2)<<a+c<<" "<<b+d<<endl;
        }
        else if(s=="-")
        {
            cout<<fixed<<setprecision(2)<<a-c<<" "<<b-d<<endl;
        }
        else if(s=="*")
        {
            cout<<fixed<<setprecision(2)<<a*c-b*d<<" "<<a*d+b*c<<endl;
        }
        else if(s=="/")
        {
            cout<<fixed<<setprecision(2)<<(a*c+b*d)/(c*c+d*d)<<" "<<(b*c-a*d)/(c*c+d*d)<<endl;
        }
    }
}