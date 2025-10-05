#include <iostream>
using namespace std;
int main() {
    int school[8];
    int mum[8];
    int record[8]={0};
    int result = 0;
    int output = 0;
    school[0]=0;
    mum[0]=0;
    cin>>school[1]>>mum[1];
    cin>>school[2]>>mum[2];
    cin>>school[3]>>mum[3];
    cin>>school[4]>>mum[4];
    cin>>school[5]>>mum[5];
    cin>>school[6]>>mum[6];
    cin>>school[7]>>mum[7];
    for(int i=1;i<=7;i++){
        record[i] = school[i]+mum[i];
        if (record[i] <= 8) {
            record[i]=0;        
        }}
    for (int i = 1; i <= 7; i++) {
        if(record[i]>result){
            result = record[i];
            output = i;
        }
    }
    cout<<output<<endl;
    return 0;
}
