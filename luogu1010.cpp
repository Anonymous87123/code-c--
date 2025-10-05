#include <iostream>
using namespace std;
int pow2(int a)
{
    int result = 1;
    for (int i = 1; i <= a; i++)
    {
        result *= 2;
    }
    return result;
}
int func(int num)
{
    for(int i = 14; i >= 0; i--){
        if (num >= pow2(i)){
            if(i == 1){cout <<"2";}
            else if(i == 0){cout << "2(0)";}
            else{cout<< "2(";
            func(i);
            cout<< ")";}
            num -= pow2(i);
            if (num!=0){cout << "+";}
        }
    }
    return 0;
}
int main(){
    int num;
    cin >> num;
    func(num);
    return 0;
}