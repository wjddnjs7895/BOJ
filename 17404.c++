#include <bits/stdc++.h>

#define INF 2134567890

using namespace std;

int N, RGB[1001][3], cache[1001][3], MIN = INF;

void func(int idx) {
  if (idx == N) return;
  cache[idx][0] = min(cache[idx - 1][1], cache[idx - 1][2]) + RGB[idx][0];
  cache[idx][1] = min(cache[idx - 1][0], cache[idx - 1][2]) + RGB[idx][1];
  cache[idx][2] = min(cache[idx - 1][0], cache[idx - 1][1]) + RGB[idx][2];
  func(idx + 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> RGB[i][0] >> RGB[i][1] >> RGB[i][2];
    cache[i][0] = cache[i][1] = cache[i][2] = INF;
  }
  cache[0][0] = RGB[0][0];
  func(1);
  MIN = min(MIN, min(cache[N-1][1], cache[N-1][2]));
  cache[0][0] = INF;
  cache[0][1] = RGB[0][1];
  func(1);
  MIN = min(MIN, min(cache[N-1][0], cache[N-1][2]));
  cache[0][1] = INF;
  cache[0][2] = RGB[0][2];
  func(1);
  MIN = min(MIN, min(cache[N-1][0], cache[N-1][1]));
  cout << MIN << endl;
}