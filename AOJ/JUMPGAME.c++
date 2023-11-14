#include <iostream>
#include <cstring>

using namespace std;

int C, N, arr[101][101], cache[101][101];

bool func(int y, int x) {
  if (y < 0 || y >= N || x < 0 || x >= N) return false;
  if (y == N - 1 && x == N - 1) return true;
  int& ret = cache[y][x];
  if (ret != 0) return false;
  if (ret == 1) return true;
  ret = func(y + arr[y][x], x) || func(y, x + arr[y][x]) ? 1 : -1;
  return ret == 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> C;
  for (int i = 0; i < C; ++i) {
    memset(cache, 0, sizeof(cache));
    cin >> N;
    for (int y = 0; y < N; ++y) {
      for (int x = 0; x < N; ++x) {
        cin >> arr[y][x];
      }
    }
    string ANS = func(0, 0) ? "YES" : "NO";
    cout << ANS << endl;
  }
}