#include <bits/stdc++.h>
#define INF 2134567890
using namespace std;

int N, scoreArr[1001], cache[1001][1001], counting[1001][1001];

void func() {
  int maxValue = -INF;
  int tcounting = 3;
  for (int y = 1; y <= N; ++y) {
    for (int x = 0; x <= y; ++x) {
      if (x == 0 && y != 1) {
        cache[y][x] = maxValue;
        counting[y][x] = tcounting + 1;
        maxValue = -INF;
        tcounting = 3;
        if (counting[y][x] >= 3) cache[y][x] = 0;
      } else {
        cache[y][x] = cache[y-1][x-1]+scoreArr[y]*x;
        counting[y][x] = counting[y-1][x-1];
      }
      maxValue = max(maxValue, cache[y][x]);
      if (maxValue == cache[y][x]) tcounting = min(tcounting, counting[y][x]);
    }
  }
  cout << maxValue << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  memset(cache, 0, sizeof(cache));
  memset(counting, 0, sizeof(counting));

  cin >> N;
  for (int i = 1; i <= N; ++i) {
    cin >> scoreArr[i];
  }
  func();
  for (int y = 0; y <= N; ++y) {
    for (int x = 0; x <= y; ++x) {
      cout << cache[y][x] << ' ';
    }
    cout << endl;
  }
  for (int y = 0; y <= N; ++y) {
    for (int x = 0; x <= y; ++x) {
      cout << counting[y][x] << ' ';
    }
    cout << endl;
  }
}