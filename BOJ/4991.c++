#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int W, H, SY, SX, RMN, board[21][21];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
bool visited[21][21][1024];

int bfs() {
  queue<pair<pair<int,int>,pair<int,int>>> Q;
  Q.push({{SY, SX},{0, RMN}});

  while(!Q.empty()) {
    int y = Q.front().first.first;
    int x = Q.front().first.second;
    int cnt = Q.front().second.first;
    int remain = Q.front().second.second;
    Q.pop();

    for (int i = 0; i < 4; ++i) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      int nrmn = remain;
      if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
      if (board[ny][nx] == -2 || visited[ny][nx][nrmn]) continue;

      if (board[ny][nx] >= 0) nrmn &= ~(1 << board[ny][nx]);
      if (nrmn == 0) return cnt + 1;
      
      Q.push({{ny, nx},{cnt + 1, nrmn}});
      visited[ny][nx][nrmn] = true;
    }
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  while(true) {
    memset(visited, 0, sizeof(visited));
    memset(board, -1, sizeof(board));
    RMN = 0;
    cin >> W >> H;
    if (W == 0 && H == 0) break;
    for (int y = 0; y < H; ++y) {
      for (int x = 0; x < W; ++x) {
        char temp;
        cin >> temp;
        if (temp == 'o') {
          SY = y;
          SX = x;
        } else if (temp == '*') {
          board[y][x] = RMN;
          RMN++;
        } else if (temp == 'x') {
          board[y][x] = -2;
        }
      }
    }
    RMN = (1 << RMN) - 1;
    cout << bfs() << endl;
  }
}