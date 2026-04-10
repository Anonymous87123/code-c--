#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> a,pair<int,int> b){
     if(a.second>b.second) return true;
     else if(a.second==b.second){
         if(a.first>b.first) return true;
     }
     return false;
}
int main(){
    int hp,atk;
    while(cin>>hp>>atk){
        int num;
        cin>>num;
        vector<pair<int,int>> monster(num);
        for(int i=0;i<num;i++){
            cin>>monster[i].first>>monster[i].second;
        }
        sort(monster.begin(),monster.end(),cmp);
        int sum=0;
        for(int i=0;i<num;i++){
            while(monster[i].first>0){
                monster[i].first-=atk;
                int temp=0;
                for(int j=i;j<num;j++){
                    temp+=monster[j].second;
                }
                sum+=temp;
            }
        }
        if(sum>hp){
            cout<<sum<<" "<<"Dead"<<endl;
        }
        else{
            cout<<sum<<" "<<"Alive"<<endl;
        }
    }
}