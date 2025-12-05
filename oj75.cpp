#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,n;
    while(cin>>m>>n)
    {
        int a[m][n];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>a[i][j];
            }
        }
        int k;
        cin>>k;
        if(k==90)
        {
            int b[n][m];
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    b[i][j] = a[m-j-1][i];
                }
            }
                    for(int i=0;i<sizeof(b)/sizeof(b[0]);i++)
        {
            for(int j=0;j<sizeof(b[0])/sizeof(b[0][0]);j++)
            {
                cout<<b[i][j]<<" ";
            }
            cout<<endl;
        }
        }
        else if(k==180)
        {
            int b[m][n];
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    b[i][j] = a[m-i-1][n-j-1];
                }
            }
                    for(int i=0;i<sizeof(b)/sizeof(b[0]);i++)
        {
            for(int j=0;j<sizeof(b[0])/sizeof(b[0][0]);j++)
            {
                cout<<b[i][j]<<" ";
            }
            cout<<endl;
        }
        }
        else if(k==270)
        {
            int b[n][m];
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    b[i][j] = a[j][n-i-1];
                }
            }
            for(int i=0;i<sizeof(b)/sizeof(b[0]);i++)
            {
            for(int j=0;j<sizeof(b[0])/sizeof(b[0][0]);j++)
            {
                cout<<b[i][j]<<" ";
            }
            cout<<endl;
            }
            
        }
    }
}
