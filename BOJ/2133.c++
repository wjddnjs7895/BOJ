#include <bits/stdc++.h>

using namespace std;

int N, cache[31];

int func(int idx) {
  int& ret = cache[idx];
  if (ret != -1) return ret;
  if (idx <0) return 0;
  else if (idx == 2) return 3;
  else if (idx % 2 != 0) return 0;

  ret = func(idx-2) * 3 + func(idx-4) * 2;
  for (int i = 3; i * 2 <= idx; ++i) {
    ret += func(idx - 2 * i) * 2;
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  memset(cache, -1, sizeof(cache));
  cache[0] = 1;
  cin >> N;
  cout << func(N) << endl;
}