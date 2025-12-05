#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        vector<int> a;
        a.push_back(n);
        while(n!=1)
        {
            if(n%2==0) {n=n/2;}
            else {n=3*n+1;}
            a.push_back(n);
        }
        for(int i:a)
        {
            cout<<i<<" ";
        }
    }
}