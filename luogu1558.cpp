#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAX=1e5;
struct node{
    int colorset;
    int lazy;
}tree[4*MAX+5];
void pushup(int p){
    tree[p].colorset=tree[p*2].colorset|tree[p*2+1].colorset;
}
void pushdown(int p){
    if(tree[p].lazy!=0){
        int c=tree[p].lazy;
        int bit=1<<(c-1);
        tree[p*2].colorset=bit;
        tree[p*2].lazy=c;
        tree[p*2+1].colorset=bit;
        tree[p*2+1].lazy=c;
        tree[p].lazy=0;
    }
}
void build(int l,int r,int p)
{
    if(l==r){
        tree[p].colorset=1;
        tree[p].lazy=0;
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,p<<1);
    build(mid+1,r,p<<1|1);
    pushup(p);
    tree[p].lazy=0;
}
void update(int l,int r,int p,int L,int R,int c)
{
    if(L<=l&&r<=R){
        tree[p].colorset=1<<(c-1);
        tree[p].lazy=c;
        return;
    }
    pushdown(p);
    int mid=(l+r)>>1;
    if(L<=mid) update(l,mid,p<<1,L,R,c);
    if(R>mid) update(mid+1,r,p<<1|1,L,R,c);
    pushup(p);
}
int query(int l,int r,int p,int L,int R)
{
    if(L<=l&&r<=R) return tree[p].colorset;
    pushdown(p);
    int mid=(l+r)>>1;
    int res=0;
    if(L<=mid) res|=query(l,mid,p<<1,L,R);
    if(R>mid) res|=query(mid+1,r,p<<1|1,L,R);
    return res;
}
main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int L,T,O;
    cin>>L>>T>>O;
    build(1,L,1);
    while(O--){
        char op;
        cin>>op;
        if(op=='C'){
            int l,r,c;
            cin>>l>>r>>c;
            if(l>r) swap(l,r);
            update(1,L,1,l,r,c);
        }else{
            int l,r;
            cin>>l>>r;
            if(l>r) swap(l,r);
            int res=query(1,L,1,l,r);
            cout<<__builtin_popcount(res)<<endl;
        }
    }
}