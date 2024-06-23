#include <iostream>
#include <cstring>

using namespace std;

int N, T, K, S, cache[10001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> N >> T;
  
  memset(cache, 0, sizeof(cache));
  for (int i = 0; i < N; ++i) {
    cin >> K >> S;
    for (int t = T; t >= K; --t) {
      cache[t] = max(cache[t - K] + S, cache[t]);
    }
  }

  cout << cache[T] << endl;
}