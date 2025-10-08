#include <iostream>
using namespace std;
int main(){
    int n;int f[1000];
    cin>>n;
    f[1]=1;
    f[2]=2;
    f[3]=2;
    for (int i=3;i<=n;i++){
        if (i%2==1){
            f[i]=f[i-1];
        }
        else{
            f[i]=f[i-1]+f[i/2];
        }
    }
    cout<<f[n];
    return 0;
}