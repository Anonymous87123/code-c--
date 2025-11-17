#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        int count = 0;
        if(n==1){
            cout<<0<<endl;
            continue;
        }
        while(n!=1)
        {
            if(n%2==0)
            {
                n/=2;
                count++;
            }
            else if(n%2==1)
            {
                if((n+1)%4==0)
                {
                    n = (n+1)/2;
                    count++;
                }
                else {
                    n=(3*n+1)/2;
                    count++;
                }
            }
        }
        cout<<count<<endl;
    }
}