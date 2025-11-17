#include<bits/stdc++.h>
using namespace std;
bool judge(int x)
{
    int y=1;int m = x*x;int temp=x;
    while(x>0)
    {
        y*=10;
        x/=10;
    }
    if((m-temp)%y==0)return true;
    else return false;
}
int main()
{
    int m,n;
    while(cin>>m>>n)
    {
        int count = 0;
        for(int i=m;i<=n;i++){
            if(judge(i))count++;
        }
        cout<<count<<endl;
    }
}