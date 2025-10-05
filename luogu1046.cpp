#include <iostream>
using namespace std;
int main() {
    int apple[10];
    int height;
    cin>>apple[0]>>apple[1]>>apple[2]>>apple[3]>>apple[4]>>apple[5]>>apple[6]>>apple[7]>>apple[8]>>apple[9];
    cin>>height;
    int counter = 0;
    for(int i=0;i<10;i++){
        if(apple[i]<=height+30){
            counter++;
        }
    }
    cout<<counter<<endl;
    return 0;
}