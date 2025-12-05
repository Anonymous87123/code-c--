#include<bits/stdc++.h>
using namespace std;
struct Student {
    string name;
    double score;
};
int main() {
    int n;
    while (cin >> n) {
        Student students[100];
        double maxScore = -1.0;
        for (int i = 0; i < n; i++) {
            cin >> students[i].name >> students[i].score;
            if (students[i].score > maxScore) {
                maxScore = students[i].score;
            }
        }
        for (int i = 0; i < n; i++) {
            if (students[i].score == maxScore) {
                cout << students[i].name << " " << fixed << setprecision(2) << students[i].score << endl;
            }
        }
    }
    return 0;
}
