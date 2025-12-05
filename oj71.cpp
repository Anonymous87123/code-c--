#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1,s2;
    while(cin>>s1>>s2)
    {
        int count=0;
        for(int i=0;i<s1.length();i++)
        {
            for(int j=0;j<s2.length();j++)
            {
                if(s1[i]==s2[j])
                {
                    count+=abs(i-j);
                }
            }
        }
        cout<<count<<endl;
    }
}