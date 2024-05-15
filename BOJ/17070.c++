#include <iostream>

using namespace std;

int N, board[17][17];
int cache[17][17][3];

void solve() {
  for(int y = 1; y <= N; ++y) {
    for (int x = 2; x <= N; ++x) {
      if (board[y][x] == 1) continue;
      if (y != 1) cache[y][x][1] = cache[y-1][x][1] + cache[y-1][x][2];
      if (x != 2) {
        cache[y][x][0] = cache[y][x-1][0] + cache[y][x-1][2];
        if (y != 1 && board[y][x-1] == 0 && board[y-1][x] == 0) cache[y][x][2] = cache[y-1][x-1][0] + cache[y-1][x-1][1] + cache[y-1][x-1][2];
      }
    } 
  }
  cout << cache[N][N][0] + cache[N][N][1] + cache[N][N][2] << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  for (int y = 1; y <= N; ++y) 
    for (int x = 1; x <= N; ++x) { 
      cin >> board[y][x];
      cache[y][x][0] = 0;
      cache[y][x][1] = 0;
      cache[y][x][2] = 0;
    }
  cache[1][2][0] = 1;
  solve();
}