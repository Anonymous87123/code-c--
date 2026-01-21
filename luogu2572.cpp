#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAX=1e5+5;
struct node{
    int sum,len;
    int lmx1,rmx1,mx1,lmx0,rmx0,mx0;
    int set,rev;
}tree[4*MAX];
int a[MAX];
node merge(node left,node right){
    node res;
    res.sum=left.sum+right.sum;
    res.len=left.len+right.len;
    res.lmx1=(left.lmx1==left.len)?left.len+right.lmx1:left.lmx1;
    res.rmx1=(right.rmx1==right.len)?right.len+left.rmx1:right.rmx1;
    res.mx1=max(max(left.mx1,right.mx1),left.rmx1+right.lmx1); 
    res.lmx0=(left.lmx0==left.len)?left.len+right.lmx0:left.lmx0;
    res.rmx0=(right.rmx0==right.len)?left.rmx0+right.len:right.rmx0;
    res.mx0=max(max(left.mx0,right.mx0),left.rmx0+right.lmx0);
    res.set=-1;
    res.rev=0;
    return res;
}
void setting(int p,int val){
    tree[p].set=val;
    tree[p].rev=0;
    if(val==1){
        tree[p].sum=tree[p].len;
        tree[p].lmx1=tree[p].rmx1=tree[p].mx1=tree[p].len;
        tree[p].lmx0=tree[p].rmx0=tree[p].mx0=0;
    }
    else{
        tree[p].sum=0;
        tree[p].lmx0=tree[p].rmx0=tree[p].mx0=tree[p].len;
        tree[p].lmx1=tree[p].rmx1=tree[p].mx1=0;
    }
}
void rev(int p){
    if(tree[p].set!=-1){
        tree[p].set^=1;
        if(tree[p].set==1){
            tree[p].sum=tree[p].len;
            tree[p].lmx1=tree[p].rmx1=tree[p].mx1=tree[p].len;
            tree[p].lmx0=tree[p].rmx0=tree[p].mx0=0;
        }
        else{
            tree[p].sum=0;
            tree[p].lmx0=tree[p].rmx0=tree[p].mx0=tree[p].len;
            tree[p].lmx1=tree[p].rmx1=tree[p].mx1=0;
        }
    }else{
        tree[p].rev^=1;
        swap(tree[p].lmx0,tree[p].lmx1);
        swap(tree[p].rmx0,tree[p].rmx1);
        swap(tree[p].mx0,tree[p].mx1);
        tree[p].sum=tree[p].len - tree[p].sum;
    }
}
void pushdown(int p){
    if(tree[p].set!=-1){
        setting(p<<1,tree[p].set);
        setting(p<<1|1,tree[p].set);
        tree[p].set=-1;
    }
    if(tree[p].rev){
        rev(p<<1);
        rev(p<<1|1);
        tree[p].rev=0;
    }
}
void pushup(int p){
    tree[p]=merge(tree[p<<1],tree[p<<1|1]);
}
void build(int l,int r,int p){
    tree[p].set=-1;
    tree[p].rev=0;
    tree[p].len=r-l+1;
    if(l==r){
        tree[p].sum=a[l];
        if(a[l]==1){
            tree[p].sum=1;
            tree[p].lmx1=tree[p].rmx1=tree[p].mx1=1;
            tree[p].lmx0=tree[p].rmx0=tree[p].mx0=0;
        }else{
            tree[p].sum=0;
            tree[p].lmx0=tree[p].rmx0=tree[p].mx0=1;
            tree[p].lmx1=tree[p].rmx1=tree[p].mx1=0;
        }
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,p<<1);
    build(mid+1,r,p<<1|1);
    pushup(p);
}
void update(int l,int r,int p,int L,int R,int op){
    if(L<=l&&r<=R){
        if(op==0||op==1)setting(p,op);
        else rev(p);
        return;
    }
    pushdown(p);
    int mid=(l+r)>>1;
    if(L<=mid) update(l,mid,p<<1,L,R,op);
    if(R>mid) update(mid+1,r,p<<1|1,L,R,op);
    pushup(p);
}
node query(int l,int r,int p,int L,int R){
    if(L<=l&&r<=R) return tree[p];
    pushdown(p);
    int mid=(l+r)>>1;
    if(R<=mid)return query(l,mid,p<<1,L,R);
    else if(L>mid) return query(mid+1,r,p<<1|1,L,R);
    else{
        node left=query(l,mid,p<<1,L,R);
        node right=query(mid+1,r,p<<1|1,L,R);
        return merge(left,right);
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    build(1,n,1);
    while(m--){
        int op;int l,r;
        cin>>op>>l>>r;
        l++;r++;
        if(op==0||op==1||op==2)update(1,n,1,l,r,op);
        else if(op==3){
            cout<<query(1,n,1,l,r).sum<<"\n";
        }
        else{
            cout<<query(1,n,1,l,r).mx1<<"\n";
        }
    }
}