#include <bits/stdc++.h>

using namespace std;

int R, C, N;
char board[102][102];
bool visited[102][102];
bool flag = true;

vector<pair<int,int>> BV, LOWBV;

int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};

void dfs(int y, int x) {
    visited[y][x] = true;
    if (y == R - 1 || board[y][x] == '.') {
        flag = false;
        return;
    }
    if (board[y + 1][x] == '.') LOWBV.push_back({y, x});
    BV.push_back({y, x});
    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (nx < 0 || nx >= C || ny < 0 || ny >= R) continue;
        if (board[ny][nx] == 'x' && !visited[ny][nx]) {
            if (ny == R - 1) {
                flag = false;
                return;
            }
            dfs(ny, nx);
        }
    }
}

int getX(int floor, int i) {
    if (i % 2 == 1) {
        for (int x = C - 1; x >= 0; --x) {
            if (board[floor][x] == 'x') {
                board[floor][x] = '.';
                return x;
            }
        }
    } else {
        for (int x = 0; x < C; ++x) {
            if (board[floor][x] == 'x') {
                board[floor][x] = '.';
                return x;
            }
        }
    }
    return -1;
}

bool isFixed() {
    if (LOWBV.size() == 0) return true;
    for (int i = 0; i < LOWBV.size(); ++i) {
        int y = LOWBV[i].first;
        int x = LOWBV[i].second;
        if (y == R - 1 || board[y + 1][x] == 'x') {
            return true;
        }
    }
    return false;
}

void moveDown() {
    while (!isFixed()) {
        for (int i = 0; i < BV.size(); ++i) {
            board[BV[i].first][BV[i].second] = '.';
            BV[i].first += 1;
        }        
        for (int i = 0; i < BV.size(); ++i) {
            board[BV[i].first][BV[i].second] = 'x';
        }        
        for (int i = 0; i < LOWBV.size(); ++i) {
            LOWBV[i].first += 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(visited, 0, sizeof(visited));

    cin >> R >> C;
    for (int y = 0; y < R; ++y) {
        for (int x = 0; x < C; ++x) {
            cin >> board[y][x];
        }
    }
    cin >> N;
    for (int i = 0; i < N; ++i) {
        BV = vector<pair<int,int>>();
        LOWBV = vector<pair<int,int>>();
        int floor;
        cin >> floor;
        floor = R - floor;
        int bx = getX(floor, i);
        if (bx != -1) {
            for (int di = 0; di < 4; ++di) {
                memset(visited, 0, sizeof(visited));
                flag = true;
                int ny = floor + dy[di];
                int nx = bx + dx[di];
                if (nx < 0 || nx >= C || ny < 0 || ny >= R) continue;
                dfs(ny, nx);
                if (flag) break;

                BV = vector<pair<int,int>>();
                LOWBV = vector<pair<int,int>>();
    
            } 
        }
        moveDown();
        memset(visited, 0, sizeof(visited));
    }
    for (int y = 0; y < R; ++y) {
        for (int x = 0; x < C; ++x) {
            cout << board[y][x];
        }
        cout << endl;
    }
}