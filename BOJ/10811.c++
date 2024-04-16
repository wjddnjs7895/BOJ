#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M, arr[101];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 1; i <= N; ++i) arr[i] = i;

  for (int i = 0; i < M; ++i) {
    int a, b, tempArr[101];
    cin >> a >> b;
    copy(arr, arr+N+1, tempArr);
    for (int idx = b; idx >= a; --idx) {
      arr[idx] = tempArr[a + b - idx];
    }
  }

  for (int i = 1; i <= N; ++i) cout << arr[i] <<' ';
}