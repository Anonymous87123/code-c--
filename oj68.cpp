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
    
}