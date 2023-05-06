#include <bits/stdc++.h>

using namespace std;

int R, C, ANSWER = 0;
char board[1501][1501];
bool lvisited[1501][1501];
bool wvisited[1501][1501];
queue<pair<int,int>> LQ;
queue<pair<int,int>> TEMP_LQ;
queue<pair<int,int>> WQ;
queue<pair<int,int>> TEMP_WQ;

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

int LBFS() {
    while(!LQ.empty()) {
        int ly = LQ.front().first;
        int lx = LQ.front().second;
        LQ.pop();

        for (int i = 0; i < 4; ++i) {
            int ny = ly + dy[i];
            int nx = lx + dx[i];
            if (ny < 0 || ny >= R || nx < 0 || nx >=C) continue;
            if (board[ny][nx] == '.' && !lvisited[ny][nx]) {
                LQ.push({ny, nx});
                lvisited[ny][nx] = true;
            } else if (board[ny][nx] == 'X' && !lvisited[ny][nx]) {
                TEMP_LQ.push({ny, nx});
                lvisited[ny][nx] = true;
            } else if (board[ny][nx] == 'L' && !lvisited[ny][nx]) {
                return ANSWER;
            }
        }
    }
    LQ = TEMP_LQ;
    TEMP_LQ = queue<pair<int,int>>();
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    memset(board, -1, sizeof(board));
    memset(lvisited, 0, sizeof(lvisited));
    memset(wvisited, 0, sizeof(wvisited));

    cin >> R >> C;
    for (int y = 0; y < R; ++y) {
        for (int x = 0; x < C; ++x) {
            cin >> board[y][x];
            if (board[y][x] == '.') {
                WQ.push({y, x});
                wvisited[y][x] = true;
            }
            else if (board[y][x] == 'L') {
                if (LQ.empty()) {
                    LQ.push({y, x});
                    lvisited[y][x] = true;
                }
                WQ.push({y, x});
                wvisited[y][x] = true;
            }
        }
    }

    if(LBFS() == 0) {
        cout << '0' << endl;
        return 0;
    }

    while(!WQ.empty()) {
        int wy = WQ.front().first;
        int wx = WQ.front().second;
        WQ.pop();

        for (int i = 0; i < 4; ++i) {
            int ny = wy + dy[i];
            int nx = wx + dx[i];
            if (ny < 0 || ny >= R || nx < 0 || nx >=C) continue;
            if (board[ny][nx] == 'X' && !wvisited[ny][nx]) {
                TEMP_WQ.push({ny, nx});
                board[ny][nx] = '.';
                wvisited[ny][nx] = true;
            } else if (board[ny][nx] == '.' && !wvisited[ny][nx]) {
                WQ.push({ny, nx});
                wvisited[ny][nx] = true;
            }
        }
        if (WQ.empty()) {
            while(!TEMP_WQ.empty()) {
                WQ.push(TEMP_WQ.front());
                TEMP_WQ.pop();
            }
            ANSWER += 1;
            int ret = LBFS();
            if (ret != -1) {
                cout << ret << endl;
                return 0;
            }
        }
    }
    return 0;
}