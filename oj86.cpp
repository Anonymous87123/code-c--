#include<bits/stdc++.h>
using namespace std;
vector<int> add(vector<int>&a,vector<int>&b){
    vector<int> c(max(a.size(),b.size())+1,0);
    int carry=0;
    for(int i=0;i<c.size();i++){
        c[i]=a[i]+b[i]+carry;
        carry=c[i]/10;
        c[i]%=10;
    }
    for(auto it=c.end()-1;it!=c.begin()&&*it==0;it--){
        if(*it==0){
            c.erase(it);
        }
        else break;
    }
    return c;
}
vector<int> multiply(vector<int>&a,vector<int>&b){
    vector<int> c(a.size()+b.size()+1,0);
    for()
}
int main(){
    string num1,num2;
    vector<int> a,b;
    while(cin>>num1>>num2){
        for(int i=num1.size()-1;i>=0;i--){
            a.push_back(num1[i]-'0');
        }
        for(int i=num2.size()-1;i>=0;i--){
            a.push_back(num2[i]-'0');
        }//a,b反向    
        cout<<add(a,b)<<" "<<multiply(a,b)<<endl;
    }
}