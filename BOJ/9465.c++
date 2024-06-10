#include <iostream>
#include <cstring>

using namespace std;

int T, N, board[2][100001], cache[2][100001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> T;
  for (int i = 0; i < T; ++i) {
    cin >> N;
    memset(board, 0, sizeof(board));
    memset(cache, 0, sizeof(cache));
    for (int y = 0; y < 2; ++y) {
      for (int x = 0; x < N; ++x) {
        cin >> board[y][x];
        cache[y][x] = board[y][x];
      }
    }
    for (int x = 0; x < N; ++x) {
      for (int y = 0; y < 2; ++y) {
        int tempY = (y+1)%2;
        if (x == 1)  cache[y][x] += cache[tempY][x-1];
        else if (x >= 2) cache[y][x] += max(cache[y][x-2],max(cache[tempY][x-2], cache[tempY][x-1]));
      }
    }

    cout << max(cache[0][N-1], cache[1][N-1]) << endl;
  }
}