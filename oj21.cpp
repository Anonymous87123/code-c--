#include <iostream>
#include <vector>
using namespace std;
void print(int n) 
{
    for(int i=1;i<=n-1;i++){cout<<" ";}cout<<"*"<<endl;
    for (int i = 2; i <= n-1; i++) 
    {
        for (int j = 1; j <= n-i; j++) {cout << " ";}cout<<"*";
        for (int k = 1; k <= i-2; k++) {cout << " ";}cout<<"*"<<endl;
    }
    for (int m = 1; m <= n-1 ; m++){cout<<"*";}cout<<"*"<<endl;
}
int main() {
    vector<int> numbers;
    int num;
    while (cin >> num) {
        numbers.push_back(num);
    }
    int n = numbers.size();
    for (int i = 0; i < n; i++) {
        print(numbers[i]);cout<<endl;
    }
    return 0;
}