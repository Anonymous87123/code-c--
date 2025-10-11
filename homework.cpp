#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n>1)
    {
        if(n%2==0)
        {
            n/=2;
            cout<<0<<"\r";
        }
        else if(n%2==1)
        {
            n=(n-1)/2;
            cout<<1<<"\r";
        }
    }
}