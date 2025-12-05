#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[224][224];
    for(int i=0;i<224;i++)
    {
        for(int j=0;j<224;j++)
        {
            a[i][j]=(i+j)%2;
        }
    }
    int x,y,d;
    while(cin>>x>>y>>d)
    {
        int count=0;
        for(int i=0;i<224;i++)
        {
            for(int j=0;j<224;j++)
            {
                if(abs(i-x)+abs(j-y)<=d&&abs(i-x)+abs(j-y)!=0)
                {
                    count+=a[i][j];
                }
            }
        }
        cout<<count<<endl;
    }
    return 0;
}