#include<bits/stdc++.h>
using namespace std;
int main()
{
    const char* s[] = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
    vector<int> n;
    int m;
    while(cin>>m){n.push_back(m);}
    for(int i:n){
        if(1<=i&&i<=7)cout<<s[i-1]<<endl;
        else cout<<"Input error!"<<endl;
    }
}
