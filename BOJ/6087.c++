#include <iostream>
#include <cstring>
#include <queue>

#define INF 987654321;

using namespace std;

int W, H, SY = -1, SX = -1, EY, EX, visited[101][101][4], cntarr[101][101];
char board[101][101];

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

int bfs() {
  queue<pair<pair<int,int>, pair<int,int>>> Q;
  Q.push({{SY, SX},{0,0}});

  while(!Q.empty()) {
    int y = Q.front().first.first;
    int x = Q.front().first.second;
    int dir = Q.front().second.first;
    int cnt = Q.front().second.second;
    Q.pop();

    for (int i = 0; i < 4; ++i) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      int c = (dir == i || (y == SY && x == SX)) ? cnt : cnt + 1;
      if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
      if (board[ny][nx] == '*') continue;
      if (cntarr[ny][nx] >= c) {
        if (cntarr[ny][nx] == c && visited[ny][nx][i]) continue;
        cntarr[ny][nx] = c;
        visited[ny][nx][i] = true;
        Q.push({{ny, nx}, {i, c}});
      }
    }
  }
  return cntarr[EY][EX];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> W >> H;

  memset(visited, 0, sizeof(visited));

  for (int y = 0; y < H; ++y) {
    for (int x = 0; x < W; ++x) {
      cin >> board[y][x];
      if (board[y][x] == 'C') {
        if (SY == -1 && SX == -1) {
          SY = y;
          SX = x;
        } else {
          EY = y;
          EX = x;
        }
      }
      cntarr[y][x] = INF;
    }
  }
  cout << bfs() << endl;
}