//本题是单点修改，不是区间修改，不用lazy标记
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAX=5e5+5;
const int INF=1e18;
int a[MAX];
int n,m;
struct node{
    int sum;
    int lmax;
    int rmax;
    int maxn;
}tree[4*MAX];
node merge(node left,node right)
{
    node res;
    res.sum=left.sum+right.sum;
    res.lmax=max(left.lmax,left.sum+right.lmax);
    res.rmax=max(right.rmax,right.sum+left.rmax);
    res.maxn=max(left.maxn,right.maxn);
    return res;
}
main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;    
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

}