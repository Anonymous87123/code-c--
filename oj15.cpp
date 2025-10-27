#include<iostream>
using namespace std;
int main()
{
    int m,n;
    while(cin>>m>>n && m!=0 && n!=0 && m>=n)
    {
        long long ans=1;
        for(int i=m;i>(m-n);i--)
        {
            ans*=i;
        }
        long long ans1 = 1;
        for(int j=n;j>0;j--)
        {
            ans1*=j;
        }
        cout<<(ans)/ans1<<endl;
    }
}