#include <iostream>
#include <cstring>

#define MOD 10007

using namespace std;

int N, cache[1001][10], result = 0;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;

  memset(cache, 0, sizeof(cache));

  for (int i = 1; i <= N; ++i) {
    for (int num = 0; num < 10; ++num) {
      if (i == 1) cache[1][num] = 1;
      else {
        cache[i][num] = cache[i - 1][num] % MOD;
        if (num != 0) cache[i][num] += (cache[i][num - 1] % MOD);
      }
      if (i == N) result += cache[i][num];
    }
  }
  cout << result % MOD << endl;
}