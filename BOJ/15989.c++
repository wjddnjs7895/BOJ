#include <iostream>

using namespace std;

int T, cache[10001][3];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> T;

  for (int i = 0; i < T; ++i) {
    int n;
    cin >> n;
    
    cache[1][0] = 1;
    cache[1][1] = 0;
    cache[1][2] = 0;

    cache[2][0] = 1;
    cache[2][1] = 1;
    cache[2][2] = 0;

    cache[3][0] = 2;
    cache[3][1] = 0;
    cache[3][2] = 1;

    for (int num = 4; num <= n; ++num) {
      cache[num][0] = cache[num - 1][0] + cache[num - 1][1] + cache[num - 1][2];
      cache[num][1] = cache[num - 2][2] + cache[num - 2][1];
      cache[num][2] = cache[num - 3][2];
    }

    cout << cache[n][0] + cache[n][1] + cache[n][2] << '\n';
  }
}