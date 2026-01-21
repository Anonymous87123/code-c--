#include<bits/stdc++.h>
using namespace std;
const int MAX=1e5+5;
double a[MAX];
struct node{
    double sum;double sqsum;
    double tag;
}tree[4*MAX];
void pushup(int p){
    tree[p].sum=tree[p<<1].sum+tree[p<<1|1].sum;
    tree[p].sqsum=tree[p<<1].sqsum+tree[p<<1|1].sqsum;
}
void build(int l,int r,int p){
    tree[p].tag=0;
    if(l==r){
        tree[p].sum=a[l];
        tree[p].sqsum=a[l]*a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,p<<1);
    build(mid+1,r,p<<1|1);
    pushup(p);
}
void addk(int l,int r,int p,double k){
    tree[p].sqsum+=2*tree[p].sum*k+(r-l+1)*k*k;
    tree[p].sum+=k*(r-l+1);
    tree[p].tag+=k;
}
void pushdown(int l,int r,int p){
    if(fabs(tree[p].tag)>1e-9){
        int mid=(l+r)>>1;
        addk(l,mid,p<<1,tree[p].tag);
        addk(mid+1,r,p<<1|1,tree[p].tag);
        tree[p].tag=0;   
    }
}
void update(int l,int r,int p,int L,int R,double val){
    if(L<=l&&r<=R){
        addk(l,r,p,val);
        return;
    }
    pushdown(l,r,p);
    int mid=(l+r)>>1;
    if(L<=mid) update(l,mid,p<<1,L,R,val);
    if(R>mid) update(mid+1,r,p<<1|1,L,R,val);
    pushup(p);
}
pair<double,double> query(int l,int r,int p,int L,int R){
    if(L<=l&&r<=R){
        return {tree[p].sum,tree[p].sqsum};
    }
    pushdown(l,r,p);
    int mid=(l+r)>>1;
    pair<double,double> res={0,0};
    if(L<=mid){
        pair<double,double> left=query(l,mid,p<<1,L,R);
        res.first+=left.first;
        res.second+=left.second;
    }
    if(R>mid){
        pair<double,double> right=query(mid+1,r,p<<1|1,L,R);
        res.first+=right.first;
        res.second+=right.second;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N,M;
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        cin>>a[i];
    }
    build(1,N,1);
    while(M--){
        int op;
        cin>>op;
        if(op==1){
            int l,r;
            double k;
            cin>>l>>r>>k;
            update(1,N,1,l,r,k);
        }
        else if(op==2){
            int l,r;
            cin>>l>>r;
            pair<double,double> res=query(1,N,1,l,r);
            double ans=res.first/(r-l+1);
            cout<<fixed<<setprecision(4)<<ans<<"\n";
        }
        else if(op==3){
            int l,r;
            cin>>l>>r;
            pair<double,double> res=query(1,N,1,l,r);
            double temp=res.first/(r-l+1);
            double ans=res.second/(r-l+1)-temp*temp;
            cout<<fixed<<setprecision(4)<<ans<<"\n";
        }
    }
}
