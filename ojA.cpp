#include <bits/stdc++.h>
using namespace std;
int seed = 0;
int getRandom() {
    seed = (25173 * seed + 13849) % 65536;
    return seed;
}
vector<vector<char>> mazeGenerator(int M, int N) {
    vector<vector<char>> maze(M, vector<char>(N, '#'));
    maze[0][1] = '.';
    maze[M-1][N-2] = '.';
    for (int i = 1; i < M - 1; i++) {
        for (int j = 1; j < N - 1; j++) {
            int r = getRandom();
            if (r < 40000) {
                maze[i][j] = '.';
            }
        }
    }
    return maze;
}
void print(const vector<vector<char>>& maze, int step, bool isForward) {
    cout << (isForward ? "前进-" : "回退-") << "步骤" << step << "：" << endl;
    for (int i = 0; i < maze.size(); i++) {
        for (int j = 0; j < maze[i].size(); j++) {
            cout << maze[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
int turnright(int dir) {
    return (dir + 1) % 4;
}
int turnleft(int dir) {
    return (dir + 3) % 4;
}
int turnback(int dir) {
    return (dir + 2) % 4;
}
bool get(int& x, int& y, int dir, int M, int N) {
    int newx = x, newy = y;
    switch (dir) {
        case 0: newx = x - 1; break;
        case 1: newy = y + 1; break;
        case 2: newx = x + 1; break;
        case 3: newy = y - 1; break;
    }
    if (newx < 0 || newx >= M || newy < 0 || newy >= N) {
        return false;
    }
    x = newx;
    y = newy;
    return true;
}
bool mazeTraverse(vector<vector<char>>& maze, int x, int y, int M, int N, int dir, int& step, bool& found) {
    if (x == M-1 && y == N-2) {
        maze[x][y] = 'X';
        print(maze, step++, true);
        found = true;
        return true;
    }
    if (maze[x][y] == '.') {
        maze[x][y] = 'X';
        print(maze, step++, true);
    }
    int curx = x, cury = y;
    int directions[4];
    directions[0] = turnright(dir);
    directions[1] = dir;
    directions[2] = turnleft(dir);
    directions[3] = turnback(dir);
    for (int i = 0; i < 4; i++) {
        int newx = curx, newy = cury;
        if (get(newx, newy, directions[i], M, N)) {
            if (maze[newx][newy] == '.') {
                bool result = mazeTraverse(maze, newx, newy, M, N, directions[i], step, found);
                if (found) {
                    return true;
                }
            }
        }
    }
    if (maze[curx][cury] == 'X') {
        maze[curx][cury] = '.';
        print(maze, step++, false);
    }
    
    return false;
}
int main() {
    int M, N;
    while (cin >> M >> N) {
        seed = 0;
        vector<vector<char>> maze = mazeGenerator(M, N);
        int step = 1;
        bool found = false;
        mazeTraverse(maze, 0, 1, M, N, 2, step, found);
        
        if (found) {
            cout << "成功走出迷宫" << endl;
        } else {
            cout << "回退到入口" << endl;
        }
    }
    return 0;
}
