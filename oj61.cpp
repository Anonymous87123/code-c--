#include<bits/stdc++.h>
using namespace std;
long long reverse(long long n) 
{
    long long rev=0;
    while(n)
    {
        rev=rev*10+n%10;
        n=n/10;
    }
    return rev;
}
bool sym(long long n)
{
    if(n==reverse(n)) return true;
    else return false;
}
int main()
{
    long long n;
    while(cin>>n)
    {int m=0;
    while(m<17)
    {
        if(sym(n))
        {
            cout<<n<<endl;
            break;
        }
        else
        {
            n=n+reverse(n);
            m++;
        }
    }
    if(m==17) cout<<"-1"<<endl;
}
}