#include<bits/stdc++.h>
using namespace std;
long long int Fib(int n)
{
    if(n==1)return 0;
    if(n==2)return 1;
    else return Fib(n-1)+Fib(n-2);
}
bool isPrime(long long int n)
{
    if(n<=1)return false;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)return false;
    }
    return true;
}
int main()
{
    int n;
    while(cin >> n)
    {
    for(int i=1;i<=n;i++)
    {
        if(isPrime(Fib(i)))cout << Fib(i) << " ";
    }
}
}