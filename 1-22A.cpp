#include<bits/stdc++.h>
using namespace std;
int main(){
    string s1,s2;
    while(getline(cin,s1) && getline(cin,s2)){
        vector<string> a;
        for(int i=0;i<s1.size();i+=8){
            string temp="";
            temp+=s1[i];temp+=s1[i+1];
            temp+=s1[i+2];temp+=s1[i+3];
            temp+=s1[i+4];temp+=s1[i+5];
            temp+=s1[i+6];temp+=s1[i+7];
            a.push_back(temp);
        }
        for(int i=0;i<s2.size();i+=8){
            string temp="";
            temp+=s2[i];temp+=s2[i+1];
            temp+=s2[i+2];temp+=s2[i+3];
            temp+=s2[i+4];temp+=s2[i+5];
            temp+=s2[i+6];temp+=s2[i+7];
            a.push_back(temp);
        }     
        sort(a.begin(),a.end(),[](string a,string b){return a<b;});
        for(string s:a){
            cout<<s;
        }
        cout<<endl;
    }
}
