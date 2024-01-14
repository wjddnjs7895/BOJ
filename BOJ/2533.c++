#include <bits/stdc++.h>

using namespace std;

int N, cache[1000001][2];
vector<vector<int>> V;
bool visited[1000001];

void func(int node) {
  visited[node] = true;
  cache[node][0] = 1;
  for (int i = 0; i < V[node].size(); ++i) {
    int next = V[node][i];
    if (visited[next]) continue;
    func(next);
    cache[node][0] += min(cache[next][0], cache[next][1]);
    cache[node][1] += cache[next][0];
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i <= N; i++) V.push_back(vector<int>());

  for (int i = 1; i < N; ++i) {
    int u, v;
    cin >> u >> v;
    V[u].push_back(v);
    V[v].push_back(u);
  }
  func(1);
  cout << min(cache[1][0], cache[1][1]) << endl;
}