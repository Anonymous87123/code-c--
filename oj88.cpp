#include<bits/stdc++.h>
using namespace std;
int main(){
    string old;
    while(cin>>old){
        string cur="";
        for(int i=0;i<=5;i++){
            cur+=old[i];
        }
        cur+="19";
        for(int i=6;i<=14;i++){
            cur+=old[i];
        }
        long long a=7*(cur[0]-'0')+9*(cur[1]-'0')+10*(cur[2]-'0')+5*(cur[3]-'0')+8*(cur[4]-'0')+4*(cur[5]-'0')+2*(cur[6]-'0')+1*(cur[7]-'0')+6*(cur[8]-'0')+3*(cur[9]-'0')+7*(cur[10]-'0')+9*(cur[11]-'0')+10*(cur[12]-'0')+5*(cur[13]-'0')+8*(cur[14]-'0')+4*(cur[15]-'0')+2*(cur[16]-'0');
        a%=11;
        if(a==0)cur+="1";
        else if(a==1)cur+="0";
        else if(a==2)cur+="X";
        else if(a==3)cur+="9";
        else if(a==4)cur+="8";
        else if(a==5)cur+="7";
        else if(a==6)cur+="6";
        else if(a==7)cur+="5";
        else if(a==8)cur+="4";
        else if(a==9)cur+="3";
        else if(a==10)cur+="2";
        cout<<cur<<endl;
    }
}