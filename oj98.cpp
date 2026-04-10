#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;int cnt=0;
    while(cin>>n>>m){
        if(1<=n&&n<=20&&cnt==0){
            cout<<"Aid:"<<n<<" "<<"prize:"<<6000+m*5<<endl;
        }
        else if(101<=n&&n<=120&&cnt==0){
            cout<<"Cid:"<<n<<" "<<"prize:"<<6000+m*1<<endl;
        }
        else if(21<=n&&n<=100){
            cout<<"Bid:"<<n<<" "<<"prize:"<<6000+m*3<<endl;
            cnt++;
        }
        else if(1<=n&&n<=20&&cnt!=0){
            cout<<"Aid:"<<n<<" "<<"prize:"<<6000+m*5-cnt*1000<<endl;
        }
        else if(101<=n&&n<=120&&cnt!=0){
            cout<<"Cid:"<<n<<" "<<"prize:"<<6000+m*1+cnt*1000<<endl;
        }      
    }
}