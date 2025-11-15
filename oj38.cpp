#include<bits/stdc++.h>
using namespace std;
bool judge(long long int n)
{
    long long int m = 0;
    while(n>0)
    {
        int k = n%10;
        n-=k;
        m+=k;
        n/=10;
        if(k==8)return true;
    }
    if(0<=m&&m<10&&m!=8)return false;
    else return judge(m);
}
int main()
{
    vector<long long int> v;
    long long int n;
    while(cin>>n)
    {
        v.push_back(n);
    }
    for(int i:v)
    {
        if(judge(i))cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}