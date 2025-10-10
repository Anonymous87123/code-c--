#include<iostream>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        for (int i = 1; i <= n; i++){cout<<"* ";}
        cout<<endl;
        for(int i1 = 1;i1<= n-2;i1++){
            cout<<"* ";
            for(int j = 1;j<=n-2;j++){cout<<"  ";}
            cout<<"*"<<endl;
        }
        for (int i = 1; i <= n; i++){cout<<"* ";}
        cout<<endl;
    }
    return 0;
}