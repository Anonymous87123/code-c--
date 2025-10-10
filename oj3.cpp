#include<iostream>
using namespace std;
int main()
{
    int n;
    while(cin>>n){
        for(int j=2;j<=n;j++)
        {
                int sum =0;
                for(int k=1;k<j;k++)
                {
                    if(j%k==0){sum+=k;}
                }
                if(sum==j){cout<<j<<" ";}
        }
    }
}
