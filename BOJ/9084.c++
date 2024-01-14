#include <bits/stdc++.h>

using namespace std;

int T, N, M, arr[21], cache[10001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> T;

  for (int t = 0; t < T; ++t) {
    memset(cache, 0, sizeof(cache));
    cache[0] = 1;
    cin >> N;
    for (int i = 0; i < N; ++i) {
      cin >> arr[i];
    }
    cin >> M;

    for (int i = 0; i < N; ++i) {
      for (int j = arr[i]; j <= M; ++j) {
        cache[j] += cache[j - arr[i]];
      }
    }
    cout << cache[M] << endl;
  }
}