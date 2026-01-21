#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAX=5e4+5;
int a[MAX];
int n,m;
struct node{
    int len;
    int lmax;
    int rmax;
    int maxx;
    int tag;
}tree[4*MAX];
node merge(node left,node right)
{
    node res;
    res.len=left.len+right.len;
    res.lmax=(left.lmax==left.len)?left.len+right.lmax:left.lmax;
    res.rmax=(right.rmax==right.len)?right.len+left.rmax:right.rmax;
    res.maxx=max(max(left.maxx,right.maxx),left.rmax+right.lmax);
    res.tag=0;
    return res;
}
void build(int l,int r,int p){
    tree[p].tag=0;
    if(l==r){
        tree[p].len=1;
        tree[p].lmax=1;
        tree[p].rmax=1;
        tree[p].maxx=1;
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,p<<1);
    build(mid+1,r,p<<1|1);
    tree[p]=merge(tree[p<<1],tree[p<<1|1]);
}
void pushdown(int p){
    if(tree[p].tag!=0){
        if(tree[p].tag==1){
            tree[p<<1].lmax=tree[p<<1].rmax=tree[p<<1].maxx=0;
            tree[p<<1|1].lmax=tree[p<<1|1].rmax=tree[p<<1|1].maxx=0;
        }else{
            tree[p<<1].lmax=tree[p<<1].rmax=tree[p<<1].maxx=tree[p<<1].len;
            tree[p<<1|1].lmax=tree[p<<1|1].rmax=tree[p<<1|1].maxx=tree[p<<1|1].len;
        }
        tree[p<<1].tag=tree[p<<1|1].tag=tree[p].tag;
        tree[p].tag=0;
    }
}
void update(int l,int r,int p,int L,int R,int val){
    if(L<=l&&r<=R){
        tree[p].tag=val;
        if(val==1){
            tree[p].lmax=tree[p].rmax=tree[p].maxx=0;
        }else{
            tree[p].lmax=tree[p].rmax=tree[p].maxx=tree[p].len;
        }
        return;
    }
    pushdown(p);
    int mid=(l+r)>>1;
    if(L<=mid) update(l,mid,p<<1,L,R,val);
    if(R>mid) update(mid+1,r,p<<1|1,L,R,val);
    tree[p]=merge(tree[p<<1],tree[p<<1|1]);
}
int query(int l,int r,int p,int x){
    if(l==r)return l;
    pushdown(p);
    int mid=(l+r)>>1;
    if(tree[p<<1].maxx>=x) return query(l,mid,p<<1,x);
    else if(tree[p<<1].rmax+tree[p<<1|1].lmax>=x)return mid-tree[p<<1].rmax+1;
    else if(tree[p<<1|1].maxx>=x)return query(mid+1,r,p<<1|1,x);
    else return 0;
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;build(1,n,1);
    while(m--){
        int op;
        cin>>op;
        if(op==1){
            int x;
            cin>>x;
            if(tree[1].maxx<x){
                cout<<0<<endl;
                continue;
            }
            int pos=query(1,n,1,x);
            cout<<pos<<endl;
            if(pos>0)update(1,n,1,pos,pos+x-1,1);
        }else{
            int x,y;
            cin>>x>>y;
            update(1,n,1,x,x+y-1,2);
        }
    }
}