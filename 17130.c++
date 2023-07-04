#include <bits/stdc++.h>
#define MINF -2134567890
using namespace std;


int N, M, cache[1001][1001];
char board[1001][1001];
pair<int,int> start;
bool check = false;

int dy[3] = {1, 0, -1};

int func(int y, int x) {
  if (y < 0 || y >= N || x < 0 || x >= M) return MINF;
  int& ret = cache[y][x];
  if (ret != -1) return ret;
  if (board[y][x] == '#') return MINF;
  else if (board[y][x] == 'O') {
    check = true;
    return ret = max(0, max(func(y+dy[0],x+1), max(func(y+dy[1],x+1),func(y+dy[2],x+1))));
  }
  return ret = max(func(y+dy[0],x+1), max(func(y+dy[1],x+1),func(y+dy[2],x+1))) + (int)(board[y][x] == 'C');
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  memset(cache, -1, sizeof(cache));
  
  cin >> N >> M;
  for (int y = 0; y < N; ++y) {
    for (int x = 0; x < M; ++x) {
      cin >> board[y][x];
      if (board[y][x] == 'R') start = {y,x};
    }
  }
  func(start.first, start.second);
  int ans = cache[start.first][start.second];
  if (!check) cout << -1 << endl;
  else cout << ans << endl;
}