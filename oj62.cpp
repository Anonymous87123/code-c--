#include<bits/stdc++.h>
using namespace std;
int main()
{
    
    int n;
    struct student
    {
        int num;
        double score1;
        double score2;
        double score;
    };
    while(cin>>n)
    {
        const int N=n;
        student stu[N];
        for(int i=0;i<n;i++)
        {
            cin>>stu[i].num>>stu[i].score1;
        }
        for(int i=0;i<n;i++)
        {
            cin>>stu[i].num>>stu[i].score2;
        }
        for(int i=0;i<n;i++)
        {
            stu[i].score=max(stu[i].score1,stu[i].score2);
        }
        sort(stu,stu+n,[](student a,student b){
            if(a.score !=b.score)return a.score>b.score;
            else return a.num<b.num;
        });
        for(int i=0;i<3;i++)
        {
            cout<<stu[i].num<<" "<<stu[i].score<<endl;
        }
    }
}