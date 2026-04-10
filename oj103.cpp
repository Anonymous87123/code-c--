#include<bits/stdc++.h>
using namespace std;
int main(){
    double o,s,c,p;
    int n;
    cin>>o>>s>>c>>p;
    while(cin>>n){
        double card_old=100.0;
        double card_stu=100.0;
        double card_com=100.0;
        while(n--){
            double price_old=p*o;
            double price_stu=p*s;
            double price_com=p*c;
            if(card_old>=price_old){
                card_old-=price_old;
                cout<<"OLDER "<<price_old<<endl;
            }else{
                cout<<"OLDER Please recharge!"<<endl;
            }
            if(card_stu>=price_stu){
                card_stu-=price_stu;
                cout<<"STUDENT "<<price_stu<<endl;
            }else{
                cout<<"STUDENT Please recharge!"<<endl;
            }
            if(card_com>=price_com){
                card_com-=price_com;
                cout<<"COMMON "<<price_com<<endl;
            }else{
                cout<<"COMMON Please recharge!"<<endl;
            }
        }
    }
}