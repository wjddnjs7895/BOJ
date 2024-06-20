#include <iostream>
#include <cstring>

#define INF 987654321

using namespace std;

int N, board[101][101], cache[101][101];

int recur(int y, int x) {
  if (y == N - 1 && x == N - 1) return 1;
  if (y >= N || x >= N) return 0;
  if (board[y][x] == 0) return 0;

  int& ret = cache[y][x];

  if (ret != 0) return ret;

  int ny = y + board[y][x];
  int nx = x + board[y][x];
  return ret = recur(ny, x) + recur(y, nx);
}  

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N; 
  memset(cache, 0, sizeof(cache));

  for (int y = 0; y < N; ++y) {
    for (int x = 0; x < N; ++x) {
      cin >> board[y][x];
    }
  }

  recur(0, 0);

  cout << cache[0][0] << endl;
}