#include<bits/stdc++.h>
using namespace std;
vector<int> add(vector<int> &b,int m)
{
    if(m<=0){return b;}
    if(b[m]==0){b[m]=1;return b;}
    else if(b[m]==1){b[m]=0;return add(b,m-1);}
}
int main()
{
    int N;
    while(cin>>N)
    {
        vector<int> a;
        int n=abs(N);
        while(n>0)
        {
            if(n%2==0)
            {
                a.push_back(0);
                n/=2;
            }
            else if(n%2==1)
            {
                a.push_back(1);
                n--;
                n/=2;
            }
        }
        vector<int> b(32,0);
        for(int i=0;i<a.size();i++)
        {
            b[i]=a[i];
        }
        reverse(b.begin(),b.end());
        if(N<0)
        {
            for(int i=0;i<32;i++)
            {
                if(b[i]==0)b[i]=1;
                else b[i]=0;
            }
            add(b,31);
        }
        cout<<"before shift: ";
        for(int i=0;i<32;i++)
        {
            cout<<b[i];
        }
        cout<<endl;
        cout<<"after shift: ";
        if(N>0)
        {
            vector<int> c(31,0);
            for(int i=4;i<=31;i++)
            {
                c[i]=b[i-4];
            }
            for(int i=0;i<=31;i++)
            {
                cout<<c[i];
            }
            cout<<endl;
        }
        else if(N<0)
        {
            vector<int> c(31,1);
            for(int i=4;i<=31;i++)
            {
                c[i]=b[i-4];
            }
            for(int i=0;i<=31;i++)
            {
                cout<<c[i];
            }
            cout<<endl;
        }


    }
}