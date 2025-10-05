#include <iostream>
using namespace std;
int main() {
    int n;
    int m = 1;
    cin >> n;
    double sum = 0;
    while(sum <= n){
        sum += (1.0/m);
        m++;
    }
    cout << m-1 << endl;
}