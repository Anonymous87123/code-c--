#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    vector<int> output;
    while(cin>>n)
    {
        vector<int> v(n);
        for(int i=0;i<n;i++)cin>>v[i];
        sort(v.begin(),v.end());
        vector<int> a(n-1);
        for(int i=0;i<n-1;i++)a[i]=v[i+1]-v[i];
        sort(a.begin(),a.end());
        output.push_back(a[0]);
        output.push_back(v[n-1]-v[0]);
    }
    for(int i=0;i<output.size();i+=2)
    {
        cout<<output[i]<<" "<<output[i+1]<<endl;
    }
    return 0;
}


