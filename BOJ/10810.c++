#include <iostream>
#include <cstring>

using namespace std;

int N, M, arr[101];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;

  memset(arr, 0, sizeof(int) * (N+1));
  for (int n = 0; n < M; ++n) {
    int i, j, k;
    cin >> i >> j >> k;
    for (int idx = i; idx <= j; ++idx) {
      arr[idx] = k;
    }
  }

  for (int i = 1; i <= N; ++i) {
    cout << arr[i] << ' ';
  }
}