#include<iostream>
#include<vector>
using namespace std;
int main()
{
    long long int n,m;
    while(cin>>n>>m)
    {
        vector<int> num1;
        vector<int> num2;
        while(n>0)
        {
            num1.push_back(n%10);
            n/=10;
        }
        while(m>0)
        {
            num2.push_back(m%10);
            m/=10;
        }
        int sum=0;
        for(int i=0;i<num1.size();i++)
        for(int j=0;j<num2.size();j++)
        {
            sum+=num1[i]*num2[j];
        }
        cout<<sum<<endl;
    }
}