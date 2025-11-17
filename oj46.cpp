#include<bits/stdc++.h>
using namespace std;
int stopCount(int s,int t,bool p)
{
    if(s==t)return 1;
    else if(p){return abs(s-t)+1;}
    else{
        if(s<t)
        {
            if(s%3==0)
            {
                if(t%3==0)return abs(s-t)/3+1;
                else{
                    t-=t%3;
                    return abs(s-t)/3+2;
                }
            }
            else{
                s-=s%3;s+=3;
                if(t%3==0)
                {
                    return abs(s-t)/3+2;
                }
                else{
                    t-=t%3;
                    return abs(s-t)/3+3;
                }
            }
        }
        if(s>t)
        {
            return stopCount(t,s,p);
        }
    }
}
int main()
{
    int s,t,p;
    while(cin>>s>>t>>p)
    {
        cout<<stopCount(s,t,p)<<endl;
    }
}