#include <iostream>
#include <cstring>

using namespace std;

int N, M, board[51][51], SY, SX, SD;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int solve() {
  int y = SY, x = SX, dir = SD, answer = 0;
  while (true) {
    int flag = 0;
    if (board[y][x] == 0) {
      board[y][x] = -1;
      answer += 1;
    }
    for (int d = 3; d >= 0; --d) {
      int nd = (dir + d) % 4;
      int ny = y + dy[nd];
      int nx = x + dx[nd];

      if (ny >= 0 && ny < N && nx >= 0 && nx < M) {
        if (board[ny][nx] == 0) {
          flag = 1;
          y = ny;
          x = nx;
          dir = nd;
          break;
        }
      }
    }

    if (flag == 0) {
      int py = y - dy[dir];
      int px = x - dx[dir];
      if (py >= 0 && py < N && px >= 0 && px < M && board[py][px] != 1) {
        y = py;
        x = px;
      } else return answer;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> M;
  cin >> SY >> SX >> SD;

  for (int y = 0; y < N; ++y) {
    for (int x = 0; x < M; ++x) {
      cin >> board[y][x];
    }
  }
  cout << solve() << endl;
}
