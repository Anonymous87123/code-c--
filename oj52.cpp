#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,n;
    while(cin>>m>>n)
    {
        vector<vector<int>> a(m,vector<int>(n));
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
            {
                for(int j=0;j<m;j++)
                {
                    a[j][i]=m*i+j+1;
                }
            }
            else if(i%2!=0)
            {
                for(int j=0;j<m;j++)
                {
                    a[m-1-j][i]=m*i+j+1;
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}