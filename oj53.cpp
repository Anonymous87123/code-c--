#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        vector<vector<int>> a(n,vector<int>(n,0));
        int m=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                a[i-j][j]=m++;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n-i;j++)
            {
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
    }}
}