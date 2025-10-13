#include<iostream>
using namespace std;
int main()
{
    int i,j,x=0;
    for(i=0;i<=3;i++){
        x++;
        for(j=0;j<=3;j++){
            if(j)continue;x++;
        }
    }
    cout<<x<<endl;
}
