#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int N, arr[101][101], result = 987654321;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

bool visited[101][101];

void dfs(pair<int,int> pos, int low, int high) {
  int y = pos.first;
  int x = pos.second;
  
  if (y == N - 1 && x == N - 1) result = min(result, high - low);
  if (y < 0 || y >= N || x < 0 || x >= N) return;

  for (int d = 0; d < 4; ++d) {
    int ny = y + dy[d];
    int nx = x + dx[d];
    if (visited[ny][nx]) continue;
    int num = arr[ny][nx];
    int nlow = min(low, num);
    int nhigh = max(high, num);

    visited[ny][nx] = true;
    dfs({ny, nx}, nlow, nhigh);
    visited[ny][nx] = false;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;

  for (int y = 0; y < N; ++y) {
    for (int x = 0; x < N; ++x) {
      cin >> arr[y][x];
      visited[y][x] = false;
    }
  }

  dfs({0, 0}, arr[0][0], arr[0][0]);

  cout << result << endl;
}