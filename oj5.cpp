#include <iostream>
using namespace std;

int main() {
    char player1, player2;
    
    while (cin >> player1 >> player2) {
        // 检查输入是否有效
        bool p1_valid = (player1 == 's' || player1 == 'r' || player1 == 'p');
        bool p2_valid = (player2 == 's' || player2 == 'r' || player2 == 'p');
        
        if (!p1_valid && !p2_valid) {
            cout << "甲方输入错 乙方输入错" << endl;
            continue;
        }
        if (!p1_valid) {
            cout << "甲方输入错" << endl;
            continue;
        }
        if (!p2_valid) {
            cout << "乙方输入错" << endl;
            continue;
        }
        
        // 判断胜负
        if (player1 == player2) {
            cout << "平局" << endl;
        }
        else if (
            (player1 == 's' && player2 == 'p') ||  // 剪刀剪布
            (player1 == 'r' && player2 == 's') ||   // 石头砸剪刀
            (player1 == 'p' && player2 == 'r')      // 布包石头
        ) {
            cout << "甲方胜" << endl;
        }
        else {
            cout << "乙方胜" << endl;
        }
    }
    
    return 0;
}