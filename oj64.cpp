#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    while(cin>>s)
    {
        int count1 = 0;
        int count2 = 0;
        int count3 = 0;
        for(char c : s)
        {
            if(c >= 'a' && c <= 'z') count2++;
            else if(c >= 'A' && c <= 'Z') count1++;
            else if(c >= '0' && c <= '9') count3++;
        }
        cout<<count1<<" "<<count2<<" "<<count3<<endl;
    }
}