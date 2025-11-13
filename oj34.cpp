#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        struct student
        {
            string name;
            int num;
        }
        student stu[n];
        for(int i=0;i<n;i++)
        {
            cin>>stu[i].name>>stu[i].num;
        }
        string s;
        cin>>s;
        for(int i=0;i<n;i++)
        {
            if(s==stu[i].name)cout<<stu[i].name<<endl;
            else cout<<"Not Found"<<endl;
        }

    }
    return 0;
}