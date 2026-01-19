#include<bits/stdc++.h>
using namespace std;
const int N=2000005;
int mp[N],p[N/10],cnt[N],r;
int qpow(int a,int b)
{
    int ans=1;
    do
    {
        if(b&1)
            ans=(long long)ans*a%r;
        a=(long long)a*a%r;
    }
    while(b/=2);
    return ans;
}
int main()
{
    int n;
    cin>>n>>r;
    int pn=0;
    for(int i=2;i<=2*n;i++)
    {
        if(!mp[i])
        {
            p[++pn]=i;
            mp[i]=i;
        }
        for(int j=1;j<=pn&&i*p[j]<=2*n;j++)
        {
            mp[i*p[j]]=p[j];
            if(i%p[j]==0)
                break;
        }
    }
    for(int i=1;i<=n;i++)
        cnt[i]=-1;
    for(int i=n+2;i<=2*n;i++)
        cnt[i]=1;
    for(int i=2*n;i>1;i--)
        if(mp[i]<i)
        {
            cnt[mp[i]]+=cnt[i];
            cnt[i/mp[i]]+=cnt[i];
        }
    int ans=1;
    for(int i=2;i<=2*n;i++)
        if(mp[i]==i)
            ans=(long long)ans*qpow(i,cnt[i])%r;
    cout<<ans<<endl;
    return 0;
}
