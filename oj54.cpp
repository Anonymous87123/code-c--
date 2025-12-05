#include<bits/stdc++.h>
using namespace std;
int main() {
    int N;
    while(cin >> N){
    vector<vector<int>> matrix(N, vector<int>(N, 0));
    int directions[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int currentDirection = 0;
    int x = 0, y = 0; 
    int num = 1; 
    while (num <= N * N) {
        matrix[x][y] = num++;
        int nextX = x + directions[currentDirection][0];
        int nextY = y + directions[currentDirection][1];
        if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N || matrix[nextX][nextY] != 0) 
        {
            currentDirection = (currentDirection + 1) % 4;
            nextX = x + directions[currentDirection][0];
            nextY = y + directions[currentDirection][1];
        }
        x = nextX;
        y = nextY;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }}
    return 0;
}