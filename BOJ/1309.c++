#include <iostream>
#include <cstring>

#define MOD 9901

using namespace std;

int N, cache[100001][3];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;

  memset(cache, 0, sizeof(cache));

  cache[0][2] = 1;

  for (int i = 1; i <= N; ++i) {
    cache[i][0] = (cache[i-1][1] + cache[i-1][2]) % MOD;
    cache[i][1] = (cache[i-1][0] + cache[i-1][2]) % MOD;
    cache[i][2] = (cache[i-1][0] + cache[i-1][1] + cache[i-1][2]) % MOD;
  }

  cout << (cache[N][0] + cache[N][1] + cache[N][2]) % MOD << endl;
}