#include<bits/stdc++.h>
using namespace std;
void print(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<i-j+1<<" ";
        }
        for(int j=1;j<=n-i;j++)
        {
            cout<<1<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int n;
    while(cin>>n){
        print(n);
        int m = 0;
        for(int i=2;i<=n;i++)
        {
            m+=i*(n-i+1);
        }
        cout<<m<<endl;
        print(n-2);
    }
}