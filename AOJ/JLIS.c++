#include <iostream>
#include <cstring>

using namespace std;

int C, N, M, cache[101][101], arr1[101], arr2[101];

int maxLen(int idx1, int idx2) {
  if (idx1 >= N || idx2 >= M) return 0;
  int& ret = cache[idx1][idx2];
  if (ret != -1) return ret;

  int num = min(idx1, idx2);

  for (int i = idx1 + 1; i < N; ++i) {
    if (num < arr1[i]) ret = max(ret, 1 + maxLen(idx1 + 1, idx2));
    for (int j = idx2 + 1; j < M; ++j) {
      if (num < arr1[j]) ret = max(ret, 1 + maxLen(i, idx2 + 1));
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> C;

  for (int i = 0; i < N; ++i) {
    memset(cache, -1, sizeof(cache));
    memset(arr1, -1, sizeof(arr1));
    memset(arr2, -1, sizeof(arr2));
    cin >> N >> M;
    for (int a = 0; a < N; ++a) cin >> arr1[a];
    for (int b = 0; b < M; ++b) cin >> arr2[b];
  }
}