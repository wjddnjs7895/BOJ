#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M, arr[101];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> M;

  for (int i = 1; i <= N; ++i) arr[i] = i;

  for (int i = 0; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    swap(arr[a], arr[b]);
  }

  for (int i = 1; i <= N; ++i) cout << arr[i] << ' ';
}