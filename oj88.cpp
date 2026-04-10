#include<bits/stdc++.h>
using namespace std;
class ID{
    public:
        string oldid;
        string newid;
        ID(string id){
            oldid=id;newid="";
        }
        void change(){
            for(int i=0;i<=5;i++){
                newid+=oldid[i];
            }
            newid+="19";
            for(int i=6;i<=14;i++){
                newid+=oldid[i];
            }
            int a=7*(newid[0]-'0')+9*(newid[1]-'0')+10*(newid[2]-'0')+5*(newid[3]-'0')+8*(newid[4]-'0')+4*(newid[5]-'0')+2*(newid[6]-'0')+1*(newid[7]-'0')+6*(newid[8]-'0')+3*(newid[9]-'0')+7*(newid[10]-'0')+9*(newid[11]-'0')+10*(newid[12]-'0')+5*(newid[13]-'0')+8*(newid[14]-'0')+4*(newid[15]-'0')+2*(newid[16]-'0');
            a%=11;
            if(a==0)newid+="1";
            else if(a==1)newid+="0";
            else if(a==2)newid+="X";
            else if(a==3)newid+="9";
            else if(a==4)newid+="8";
            else if(a==5)newid+="7";
            else if(a==6)newid+="6";
            else if(a==7)newid+="5";
            else if(a==8)newid+="4";
            else if(a==9)newid+="3";
            else if(a==10)newid+="2";
            cout<<newid<<endl;
        }
};

int main(){
    string old;
    while(cin>>old){
        ID id(old);
        id.change();
    }
}