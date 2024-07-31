#include <iostream>
#include <cstring>

using namespace std;

int N, L, board[101][101], counting, answer = 0, installed[101][101];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> L;

  for (int y = 0; y < N; ++y)
    for (int x = 0; x < N; ++x)
      cin >> board[y][x];

  memset(installed, 0, sizeof(installed));

  for (int y = 0; y < N; ++y) {
    counting = 1;
    for (int x = 1; x < N; ++x) {
      int prev = board[y][x-1];
      int cur = board[y][x];

      if (cur == prev) counting += 1;
      else if (cur - prev == 1) {
        if (counting >= L) {
          int flag = 0;
          counting = 1;
          for (int d = 1; d <= L; ++d) {
            if (!installed[y][x-d]) installed[y][x-d] = 1;
            else {
              flag = 1;
              break;
            }
          }
          if (flag) break;
        }
        else break;
      } else if (prev - cur == 1) {
        if (N - x >= L) {
          int flag = 0;
          for (int tx = x; tx < x + L - 1; ++tx) {
            if (board[y][tx] != board[y][tx + 1] && !installed[y][tx]) {
              flag = 1;
              break;
            } else installed[y][tx] = 1;
          }
          if (!installed[y][x + L - 1]) installed[y][x+L-1] = 1;
          else break;
          if (flag) break;
        } else break;
      } else break;
      if (x == N - 1) answer += 1;
    }
  }

  memset(installed, 0, sizeof(installed));

  for (int x = 0; x < N; ++x) {
    counting = 1;
    for (int y = 1; y < N; ++y) {
      int prev = board[y-1][x];
      int cur = board[y][x];

      if (cur == prev) counting += 1;
      else if (cur - prev == 1) {
        if (counting >= L) {
          int flag = 0;
          counting = 1;
          for (int d = 1; d <= L; ++d) {
            if (!installed[y-d][x]) installed[y-d][x] = 1;
            else {
              flag = 1;
              break;
            }
          }
          if (flag) break;
        }
        else break;
      } else if (prev - cur == 1) {
        if (N - y >= L) {
          int flag = 0;
          for (int ty = y; ty < y + L - 1; ++ty) {
            if (board[ty][x] != board[ty + 1][x] && !installed[ty][x]) {
              flag = 1;
              break;
            } else installed[ty][x] = 1;
          }
          if (!installed[y + L -1][x]) installed[y+L-1][x] = 1;
          else break;
          if (flag) break;
        } else break;
      } else break;
      if (y == N - 1) answer += 1;
    }
  }

  cout << answer << endl;
}