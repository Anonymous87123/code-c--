#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,n;
    while(cin>>m>>n)
    {
        vector<vector<int>> a(m,vector<int>(n));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>a[i][j];
            }
        }
        vector<vector<int>> b(m,vector<int>(n));
        b[0][0]=(a[0][1]+a[1][0]+a[1][1]+a[0][0])/4;
        b[0][n-1]=(a[0][n-2]+a[1][n-1]+a[1][n-2]+a[0][n-1])/4;
        b[m-1][0]=(a[m-2][0]+a[m-1][1]+a[m-2][1]+a[m-1][0])/4;
        b[m-1][n-1]=(a[m-2][n-1]+a[m-1][n-2]+a[m-2][n-2]+a[m-1][n-1])/4;
        for(int i=1;i<m-1;i++)
        {
            b[i][0]=(a[i-1][0]+a[i-1][1]+a[i][1]+a[i][0]+a[i+1][1]+a[i+1][0])/6;
            b[i][n-1]=(a[i-1][n-1]+a[i-1][n-2]+a[i][n-2]+a[i][n-1]+a[i+1][n-2]+a[i+1][n-1])/6;
        }
        for(int j=1;j<n-1;j++)
        {
            b[0][j]=(a[0][j-1]+a[1][j-1]+a[0][j]+a[1][j]+a[1][j+1]+a[0][j+1])/6;
            b[m-1][j]=(a[m-1][j-1]+a[m-2][j-1]+a[m-2][j]+a[m-1][j]+a[m-2][j+1]+a[m-1][j+1])/6;
        }
        for(int i=1;i<=m-2;i++)
        {
            for(int j=1;j<=n-2;j++)
            {
                b[i][j]=(a[i-1][j-1]+a[i-1][j]+a[i-1][j+1]+a[i][j-1]+a[i][j]+a[i][j+1]+a[i+1][j-1]+a[i+1][j]+a[i+1][j+1])/9;
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<b[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}