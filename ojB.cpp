#include<bits/stdc++.h>
using namespace std;
int cmp(vector<int>&a,vector<int>&b)
{
    if(a.size()>b.size())return 1;
    else if(a.size()<b.size())return -1;
    else
    {
        for(int i=0;i<a.size();i++)
        {
            if(a[i]>b[i])return 1;
            else if(a[i]<b[i])return -1;
        }
        return 0;
    }
}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    vector<int>num1;
    vector<int>num2;
    int count=0;
    for(char c:s1)
    {
        if(c=='0')num1.push_back(0);
        else if(c=='1')num1.push_back(1);
        else if(c=='2')num1.push_back(2);
        else if(c=='3')num1.push_back(3);
        else if(c=='4')num1.push_back(4);
        else if(c=='5')num1.push_back(5);
        else if(c=='6')num1.push_back(6);
        else if(c=='7')num1.push_back(7);
        else if(c=='8')num1.push_back(8);
        else if(c=='9')num1.push_back(9);
        else if(c=='-')count++;
    }
    for(char c:s2)
    {
        if(c=='0')num2.push_back(0);
        else if(c=='1')num2.push_back(1);
        else if(c=='2')num2.push_back(2);
        else if(c=='3')num2.push_back(3);
        else if(c=='4')num2.push_back(4);
        else if(c=='5')num2.push_back(5);
        else if(c=='6')num2.push_back(6);
        else if(c=='7')num2.push_back(7);
        else if(c=='8')num2.push_back(8);
        else if(c=='9')num2.push_back(9);
        else if(c=='-')count++;
    }
    int n=max(num1.size(),num2.size());
    num1.resize(n,0);
    num2.resize(n,0);
    if(count%2==1)
    {
        //高精度减法
        if(cmp(num1,num2)==1)
        {

        }
    }

}