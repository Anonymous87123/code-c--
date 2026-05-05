#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    while(getline(cin,s)){
        vector<int>a;
        for(char c:s){
            if(isdigit(c)){
                a.push_back(c-'0');
            }
            else continue; 
        }
        sort(a.begin(),a.end(),[](int x, int y){return x < y;});
        for(int i=0;i<a.size();i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
}