#include<bits/stdc++.h>
using namespace std;
template<class T>
class fuck{};
int main(){
    int n;
    while(cin>>n){
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        int k;
        cin>>k;
        for(int i=0;i<n;i++){
            if(a[i]>=k)cout<<a[i]<<" ";
            else continue;
        }cout<<endl;
    }
}