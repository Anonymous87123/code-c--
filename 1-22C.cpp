#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
using namespace std;
const ull mod1=1222827239;
const ull mod2=(1<<31)-1;
const ull mod3=1e9+7;
const int base1=131;
const int base2=13331;
const int base3=13131;
const int MAXLEN=10000;
struct hash_pair{
    template<class T1,class T2>
    size_t operator()(const pair<T1,T2>&p)const{
        auto hash1=hash<T1>{}(p.first);
        auto hash2=hash<T2>{}(p.second);
        return hash1^(hash2<<1);
    }
};
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    unordered_set<pair<ull,ull>,hash_pair>s;
    s.reserve(n);string str;
    for(int i=0;i<n;i++){
        cin>>str;
        ull h1=0,h2=0,h3=0;
        for(auto c:str){
            h1=(h1*base1+(unsigned char)c)%mod1;
            h2=(h2*base2+(unsigned char)c)%mod2;
            h3=(h3*base3+(unsigned char)c)%mod3;
        }
        ull key1=h1*mod2+h2;ull key2=h3;
        s.insert({key1,key2});
    }
    cout<<s.size()<<endl;
}