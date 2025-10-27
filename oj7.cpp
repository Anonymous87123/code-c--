#include<iostream>
using namespace std;
int main()
{
    int i=0,j=5;
    do{i++;j--;
    if(i>3)break;}while(j>0);
    cout<<"i= "<<i<<endl<<"j= "<<j<<endl;
}