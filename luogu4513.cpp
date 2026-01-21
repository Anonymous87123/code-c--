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
    res.maxn=max({left.maxn, right.maxn, left.rmax + right.lmax});
    return res;
}
void build(int l,int r,int p)
{
    if(l==r){
        tree[p].sum=a[l];
        tree[p].lmax=a[l];
        tree[p].rmax=a[l];
        tree[p].maxn=a[l]; 
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,p<<1);
    build(mid+1,r,p<<1|1);
    tree[p]=merge(tree[p<<1],tree[p<<1|1]);
}
void update(int l,int r,int p,int idx,int val)
{
    if(l==r){
        tree[p].sum=val;
        tree[p].lmax=val;
        tree[p].rmax=val;
        tree[p].maxn=val;
        return;
    }
    int mid=(l+r)>>1;
    if(idx<=mid) update(l,mid,p<<1,idx,val);
    else update(mid+1,r,p<<1|1,idx,val);
    tree[p]=merge(tree[p<<1],tree[p<<1|1]);
}
node query(int l,int r,int p,int L,int R)
{
    if(L<=l&&r<=R) return tree[p];
    int mid=(l+r)>>1;
    if(R<=mid) return query(l,mid,p<<1,L,R);
    else if(L>mid) return query(mid+1,r,p<<1|1,L,R);
    else{
        node left=query(l,mid,p<<1,L,R);
        node right=query(mid+1,r,p<<1|1,L,R);
        return merge(left,right);
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;    
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build(1,n,1);
    while(m--){
        int opt;
        cin>>opt;
        if(opt==1){
            int a,b;
            cin>>a>>b;
            if(a>b)swap(a,b);
            node res=query(1,n,1,a,b);
            cout<<res.maxn<<endl;
        }
        else if(opt==2){
            int a,b;
            cin>>a>>b;
            update(1,n,1,a,b);
        }
    }
    return 0;
}