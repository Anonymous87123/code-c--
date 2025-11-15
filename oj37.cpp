#include<bits/stdc++.h>
using namespace std;
int generate(int &r)
{
    
    do{
        r = (25173*r+13849)%65536;
    }while(r>=100||r==0);
    return r;
}
int main()
{
    int n;int r = 0;
    while(cin>>n)
    {
        vector<int> v(n);
        for(int i=0;i<n;i++)
        {
            r = generate(r);
            v[i] = r;
        }
        for(int i=0;i<n;i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
        reverse(v.begin(),v.end());
        for(int i=0;i<n;i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
}