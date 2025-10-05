#include <iostream>
using namespace std;
int main() {
    int l,m,begin,end;
    int counter = 0;
    cin >> l >> m;
    int array[l+1];
    for(int i=0;i<=l;i++){array[i] = 1;}
    for(int i=0;i<m;i++){
        cin>> begin >> end;
        for (int j = begin;j<=end;j++){
            array[j]=0;
        }}
    for(int i=0;i<=l;i++){
        if (array[i]>0){
            counter++;
    }}
    cout<<counter<<endl;
}