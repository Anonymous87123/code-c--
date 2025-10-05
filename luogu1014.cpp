#include <iostream>
using namespace std;
int main() {
    long long n;
    cin >> n;
    long long i=1;
    while(i*(i+1)<2*n) {
        i++;
    }
    long long remainder = n-((i*(i-1))/2);
    if (i%2==0){
        cout << remainder << "/" << i+1-remainder << endl;
    }
    if (i%2==1){
        cout << i+1-remainder << "/" << remainder << endl;
    }
    return 0;
}