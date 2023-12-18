#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int N, M, K, cache[301][301], ANS = 0;
vector<pair<int,int>> V[301];

int func(int idx, int capacity) {
  if (capacity == M && idx != N) {
    return -INF;
  }
  if (idx == N) return 0;
  int& ret = cache[idx][capacity];
  if (ret != -1) return ret;
  ret = -INF;
  for (int i = 0; i < V[idx].size(); ++i) {
    int next = V[idx][i].first;
    int satisfy = V[idx][i].second;
    if (idx >= next) continue;
    ret = max(satisfy + func(next, capacity+1), ret);
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  memset(cache, -1, sizeof(cache));
  cin >> N >> M >> K;
  for (int i = 0; i < K; ++i) {
    int u, v, c;
    cin >> u >> v >> c;
    V[u].push_back({v, c});
  }
  cout << func(1, 1) << endl;
  return 0;
}