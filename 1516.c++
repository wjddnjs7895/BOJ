#include <bits/stdc++.h>

using namespace std;

int N, cache[501], cost[501], entry[501];
vector<vector<int>> V;
queue<int> Q;

void func() {
  while (!Q.empty()) {
    int idx = Q.front();
    Q.pop();
    for (int i = 0; i < V[idx].size(); ++i) {
      int np = V[idx][i];
      cache[np] = max(cache[np], cache[idx] + cost[np]);
      entry[np]--;
      if (entry[np] == 0) Q.push(np);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  memset(cache, 0, sizeof(cache));
  memset(entry, 0, sizeof(entry));
  cin >> N;
  for (int i = 0; i <= N; ++i) V.push_back(vector<int>());
  for (int i = 1; i <= N; ++i) {
    cin >> cost[i];
    while(true) {
      int temp;
      cin >> temp;
      if (temp == -1) break;
      V[temp].push_back(i);
      entry[i]++;
    }
  }
    for (int i = 1; i <= N; ++i) {
      if (entry[i] == 0) {
        Q.push(i);
        cache[i] = cost[i];
      }
    }

  func();

  for (int i = 1; i <= N; ++i) {
    cout << cache[i] << endl;
  }
}