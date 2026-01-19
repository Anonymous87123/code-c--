#include<bits/stdc++.h>
using namespace std;
#define int long long
int f(int n)
{
    if(n==1)return 1;
    else return (4*n-2)*f(n-1)/(n+1);
}
main()
{
    int n;
    cin>>n;
    cout<<f(n)<<endl;
}