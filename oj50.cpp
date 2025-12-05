#include<bits/stdc++.h>
using namespace std;
int main()
{
    
    int n;
    while(cin>>n&&n!=0)
    {
        cin>>n;
        vector<int> a(2*n);
        int k;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];a[i+n]=a[i];
        }
        cin>>k;k=k%n;
        for(int i=k+1;i<=k+7;i++)
        {
            cout<<a[i]<<" ";
        }
    }
}