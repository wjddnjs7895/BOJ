#include <iostream>
#include <cstring>

using namespace std;

int N, M, board[1025][1025], sumBoard[1025][1025];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> M;

  memset(sumBoard, 0, sizeof(sumBoard));

  for (int y = 1; y <= N; ++y) {
    for (int x = 1; x <= N; ++x) {
      cin >> board[y][x];
      if (x == 1 && y == 1) sumBoard[y][x] = board[y][x];
      else if (y == 1) sumBoard[y][x] = sumBoard[y][x-1] + board[y][x];
      else if (x == 1) sumBoard[y][x] = sumBoard[y-1][x] + board[y][x];
      else sumBoard[y][x] = sumBoard[y-1][x] + sumBoard[y][x-1] - sumBoard[y-1][x-1] + board[y][x];
    }
  }

  for (int i = 0; i < M; ++i) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << sumBoard[x2][y2] - sumBoard[x1-1][y2] - sumBoard[x2][y1-1] + sumBoard[x1-1][y1-1] << '\n';
  }
}