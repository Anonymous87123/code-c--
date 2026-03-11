#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    if(b==0)
    return a;
    return gcd(b,a%b);
}
int main(){
    int a,b;
    while(cin>>a>>b){
        if(a*b<0){
            a=abs(a);
            b=abs(b);
            int c=gcd(a,b);
            a/=c;b/=c;
            cout<<"-"<<a<<'/'<<b<<endl;
        }
        else{
            a=abs(a);
            b=abs(b);
            int c=gcd(a,b);
            a/=c;b/=c;
            cout<<a<<'/'<<b<<endl;
        }
    }
}