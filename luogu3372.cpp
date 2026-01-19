#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAX = 1e5+5;
struct node{
    int sum;
    int tag;
}tree[4*MAX];
int n,m;
int a[MAX];
void build(int l,int r,int p)
{
    tree[p].tag=0;
    if(l==r){
        tree[p].sum=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,p<<1);
    build(mid+1,r,p<<1|1);
    tree[p].sum=tree[p<<1].sum+tree[p<<1|1].sum;
}
void pushdown(int l,int r,int p)
{
    if(tree[p].tag!=0){
        int mid=(l+r)>>1;
        tree[p<<1].sum+=(mid-l+1)*tree[p].tag;
        tree[p<<1].tag+=tree[p].tag;
        tree[p<<1|1].sum+=(r-mid)*tree[p].tag;
        tree[p<<1|1].tag+=tree[p].tag;
        tree[p].tag=0;
    }
}
void update(int l,int r,int p,int L,int R,int val)
{
    if(L<=l&&r<=R)
    {
        tree[p].sum+=(r-l+1)*val;
        tree[p].tag+=val;
        return;
    }
    pushdown(l,r,p);
    int mid=(l+r)>>1;
    if(L<=mid) update(l,mid,p<<1,L,R,val);
    if(R>mid) update(mid+1,r,p<<1|1,L,R,val);
    tree[p].sum=tree[p<<1].sum+tree[p<<1|1].sum;
}
int query(int l,int r,int p,int L,int R)
{
    if(L<=l&&r<=R) return tree[p].sum;
    pushdown(l,r,p);
    int mid=(l+r)>>1;
    int res=0;
    if(L<=mid) res+=query(l,mid,p<<1,L,R);
    if(R>mid) res+=query(mid+1,r,p<<1|1,L,R);
    return res;
}
main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1,n,1);
    for (int i = 1; i <= m; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r, val;
            cin >> l >> r >> val;
            update(1, n, 1, l, r, val);
        } else {
            int l, r;
            cin >> l >> r;
            cout << query(1, n, 1, l, r) << "\n";
        }
    }
    return 0;
}