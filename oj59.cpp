#include<bits/stdc++.h>
using namespace std;
int main() {
    string line;
    while (getline(cin, line)) {
        int countA = 0, countE = 0, countI = 0, countO = 0, countU = 0;
        for (char c : line) {
            c = toupper(c);
            switch (c) {
                case 'A': countA++; break;
                case 'E': countE++; break;
                case 'I': countI++; break;
                case 'O': countO++; break;
                case 'U': countU++; break;
            }
        }
        cout << "A: " << countA << endl;
        cout << "E: " << countE << endl;
        cout << "I: " << countI << endl;
        cout << "O: " << countO << endl;
        cout << "U: " << countU << endl;
    }
    return 0;
}