#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        int count = 0;
        int die = 0;
        int wheel = 0
        while(die<=n-1)
        {
            wheel++;
            if(wheel==n+1)wheel=1;
            count++;
            if(count==3)count=1;
            die+=count;
        }
    }
}