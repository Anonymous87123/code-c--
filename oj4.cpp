#include<iostream>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        for(int i=2;i<n+1;i++)
        while(n%i==0){n/=i;cout<<i<<"\t";}
    }
}