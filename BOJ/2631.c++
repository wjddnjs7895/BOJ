#include <bits/stdc++.h>

using namespace std;

int N, cache[201], MAX = 0;
vector<int> V;

void func(int idx) {
  int& ret = cache[idx];
  if (idx == N) return;
  for (int i = 0; i < idx; ++i) {
    int comp = cache[i];
    if (V[i] <= V[idx]) {
      ret = max(ret, comp + 1);
    }
  }
  MAX = max(MAX, ret);
  func(idx + 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; ++i) {
    cache[i] = 1;
    int temp;
    cin >> temp;
    V.push_back(temp);
  }
  func(0);
  cout << N - MAX << endl;
}