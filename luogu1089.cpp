#include <iostream>
using namespace std;
int main() {
    int money[13];
    int result = 0;
    int budget[13];
    int deposit = 0;
    budget[0] = 0;//表示第i个月的预算
    money[0] = 0;//表示i月末剩余的钱
    cin >> budget[1];
    cin >> budget[2];    
    cin >> budget[3];
    cin >> budget[4];
    cin >> budget[5];
    cin >> budget[6];
    cin >> budget[7];
    cin >> budget[8];
    cin >> budget[9];
    cin >> budget[10];
    cin >> budget[11];
    cin >> budget[12];
    for(int i=1;i<=12;i++){
        money[i] = money[i-1]+ 300 - budget[i];//表示i月末剩余的钱
        while(money[i] >= 100){
            money[i] -= 100;
            deposit += 100;
        }
        if (money[i] < 0){
            cout << -i << endl;
            break;
        }
    }
    if (money[1]>=0&&money[2]>=0&&money[3]>=0&&money[4]>=0&&money[5]>=0&&money[6]>=0&&money[7]>=0&&money[8]>=0&&money[9]>=0&&money[10]>=0&&money[11]>=0&&money[12]>=0){
    result = money[12] + deposit*1.2;
    cout << result << endl;}
}
