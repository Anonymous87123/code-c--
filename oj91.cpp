#include<bits/stdc++.h>
using namespace std;
class Time{
public:
    int hour,minute,second;
    Time(int h=0,int m=0,int s=0):hour(h),minute(m),second(s){};
    Time operator+(const Time& other) const{
        int total_second=hour*3600+minute*60+second;
        int other_total_second=other.hour*3600+other.minute*60+other.second;
        int sum_second=total_second+other_total_second;
        int sum_hour=sum_second/3600;
        int sum_minute=(sum_second%3600)/60;
        int sum_second_left=sum_second%60;
        return Time(sum_hour,sum_minute,sum_second_left);
    }
    Time operator-(const Time& other) const{
        int total_second=hour*3600+minute*60+second;
        int other_total_second=other.hour*3600+other.minute*60+other.second;
        int diff_second=total_second-other_total_second;
        int diff_hour=diff_second/3600;
        int diff_minute=(diff_second%3600)/60;
        int diff_second_left=diff_second%60;
        return Time(diff_hour,diff_minute,diff_second_left);
    }
    bool operator>(const Time& other) const{
        int total_second=hour*3600+minute*60+second;
        int other_total_second=other.hour*3600+other.minute*60+other.second;
        return total_second>other_total_second;
    }
    void display()const{
        cout<<hour<<":"<<minute<<":"<<second;
    }
};
int main(){
    int n;
    cin>>n;
    while(n--){
        int h,m,s,h1,m1,s1;
        cin>>h>>m>>s>>h1>>m1>>s1;
        Time t1(h,m,s);
        Time t2(h1,m1,s1);
        Time t3=t1+t2;
        t3.display();
        cout<<" ";
        if(t1>t2){
            (t1-t2).display();
        }else{
            (t2-t1).display();
        }
        cout<<endl;
    }
}