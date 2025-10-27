#include<iostream>
#include<cmath>
using namespace std;
bool like11(int n)
{
    int a[int((log(double(n))/log(10.0))+1)];
    int l=0;
    while(n>0)
    {
        a[l]=n%10;
        l++;
        n/=10;
    }
    for(int i=0;i<l;i++)
    for(int j=i+1;j<l;j++)
    {
        if(a[i]==a[j]) return false;
    }
    return true;
}
int main()
{
    int n;
    while(cin>>n)
    {
        int count=1;
        if(n==0){cout<<1<<endl;}
        else if(n==1)
        {
            cout<<10<<endl;
        }
        else if(n>=2){
        for(int i=1;i<=pow(10,n);i++)
        {
            if(like11(i)==true) count++;
        }
        cout<<count<<endl;}
    }
}