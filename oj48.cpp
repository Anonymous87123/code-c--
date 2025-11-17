#include<bits/stdc++.h>
using namespace std;
bool isPrime(int n)
{
    if(n<=1) return false;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0) return false;
    }
    return true;
}
int reverseNum(int n)
{
    int result = 0;
    while(n>0)
    {
        result = result*10 + n%10;
        n/=10;
    }
    return result;
}
int main() {
    long long a, b, cnt = 0;
    while (cin >> a >> b) {
        cnt = 0;
        for (long long x = a; x <= b; ++x) {
            // 满足条件：x 非素数 且 x 的反转数是素数
            if (!isPrime(x) && isPrime(reverseNum(x))) {
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}
