#include <iostream>
#include <limits>
using namespace std;
int gen(int &r, int choose_difficulty) {
    do {
        r = (25173 * r + 13849) % 65536;
    } while (
        (choose_difficulty == 1 && (r >= 10)) || 
        (choose_difficulty == 2 && (r < 10 || r >= 100))
    );
    return r;
}
int main() {
    int times;
    cin>>times;
    for(int k=1;k<=times;k++)
    {
        char whether_to_start;int choose_difficulty;char operation;int points = 0;int r=0;bool skip=false;
        cout << "Start now? (Y or N)" << endl;
        while (cin >> whether_to_start) 
        {
            if (whether_to_start == 'Y') {break;}
            if (whether_to_start == 'N') {skip=true;break;}          
            cout << "Input error, please re-enter!" << endl;
        }
        if(skip)continue;
        cout << "Please enter difficulty (1 or 2):" << endl;
        while (cin >> choose_difficulty) 
        {
            if (choose_difficulty == 1 || choose_difficulty == 2) break;
            else {cout << "Input error, please re-enter!" << endl;}
        }
        cout << "Please enter type of operation (+, -, *, /):" << endl;
        while (cin >> operation) 
        {
            if (operation == '+' || operation == '-' || operation == '*' || operation == '/') break;
            else {cout << "Input error, please re-enter!" << endl;}
        }
        for (int i = 1; i <= 10; i++) 
        {
            int a = gen(r, choose_difficulty);
            int b = gen(r, choose_difficulty);
            if (operation == '-') 
            {
                while (a < b) {
                    a = gen(r, choose_difficulty);
                    b = gen(r, choose_difficulty);
                }
            }
            else if (operation == '/') {
                while (b == 0 || a % b != 0) {
                    a = gen(r, choose_difficulty);
                    b = gen(r, choose_difficulty);
                }
            }
            cout << a << operation << b << "="<<endl;
            int input;
            cin >> input;
            bool correct = false;
            switch (operation) {
                case '+': correct = (input == a + b); break;
                case '-': correct = (input == a - b); break;
                case '*': correct = (input == a * b); break;
                case '/': correct = (input == a / b); break;
            }
            if (correct) {cout << "You're right, get 10 points." << endl;points += 10;} 
            else {cout << "answer incorrectly."<<endl;}
        }
        cout << "Your grades are: " << points << endl;
    }
}
