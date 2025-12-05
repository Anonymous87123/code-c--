#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1,s2;
    while(cin>>s1>>s2)
    {
        vector<char> v1,v2;
        for(char c : s1)
        {
            v1.push_back(c);
        }
        for(char c : s2)
        {
            v2.push_back(c);
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        if(v1==v2)
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }
}