#include <bits/stdc++.h>
#define int long long
using namespace std;
int exgcd(int a,int b,int& x,int& y)
{
    if(!b){x=1;y=0;return a;}
    int d = exgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
main()
{
    int x,y,m,n,L;
    int a,b;
    cin>>x>>y>>m>>n>>L;
    int d=exgcd(n-m,L,a,b);//d=gcd(m-n,L)
    int mod=abs(L/d);
    if((x-y)%d!=0){
        cout<<"Impossible"<<endl;
        return 0;
    }
    a=((a*(x-y)/d)%mod+mod)%mod;
    cout<<a<<endl;
    return 0;
}