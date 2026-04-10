#include<bits/stdc++.h>
using namespace std;
template<class T>
class fuck{};
int main(){
    int n;
    while(cin>>n){
        vector<int> a;
        for(int i=0;i<n;i++) {
            int num;cin>>num;
            bool flag=false;
            for(int j=0;j<a.size();j++){
                if(a[j]==num){
                    flag=true;
                    break;
                }
            }
            if(flag==false){
                a.push_back(num);
            }
        }
        for(int i:a){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}