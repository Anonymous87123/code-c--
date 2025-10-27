#include<iostream>
using namespace std;
void print(int n)
{
    for(int i=n;i>=1;i--)
    {
        if(i==n){for(int j=1;j<=i;j++){cout<<"*";}cout<<endl;}
        else if(i>1)
        {
            cout<<"*";
            for(int k=1;k<=i-2;k++)
            {
                cout<<" ";
            }
            cout<<"*"<<endl;
        }
        else{cout<<"*"<<endl;}
    }
}
int main()
{
    int n;
    while(cin>>n)
    {
        print(n);cout<<endl;
    }
}
int multply(int n)
{
    int result=1;
    for(int i=1;i<=n;i++)
    {result*=i;}
}
