#include<iostream>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        int count=0;
        if(n==1){cout<<0<<endl;break;}
        while(n!=1)
        {
            if(n%2==0)
            {
                count++;
                n/=2;
            }
            else if(n%2==1)//必须用else if
            {
                count++;
                n=3*n+1;
                n/=2;
            }
        }
        cout<<count<<endl;
    }
}
