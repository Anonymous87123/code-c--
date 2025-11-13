#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        vector<int> num(n);
        for(int i=0;i<n;i++)
        {
            cin>>num[i];
        }
        int a;
        cin >> a;
        int i;
        for(i=0;i<n;i++)
        {
            if(num[i]>a){break;}
        }
        auto it = num.begin()+i;
        num.insert(it,a);
        num.erase(num.begin()+n);
        for(int i=0;i<n;i++)
        {   
            cout<<num[i]<<" ";
        }
    }
    return 0;
}