#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;//采药时间
    int M;//药物种类
    cin>>T>>M;
    vector<int> dp(T+1,0);// dp[j] 表示时间 j 内的最大价值
    for(int i=1;i<=M;i++)
    {
        int time,value;
        cin>>time>>value;
        for(int j=T;j>=time;j--)//j>=time要求剩余的j时间够当前的采药所需要的时间
        {
            dp[j]=max(dp[j],dp[j-time]+value);
        }
    }
    cout<<dp[T]<<endl;
}