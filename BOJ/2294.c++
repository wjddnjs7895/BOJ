#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

#define INF 987654321

using namespace std;

int N, K, cache[10001], answer;
vector<int> CV;

void solve() {
  for (int idx = 0; idx <= K; ++idx) {
    for (int i = 0; i < CV.size(); ++i) {
      int cost = CV[i];
      if (idx - cost >= 0) cache[idx] = min(cache[idx], cache[idx-cost] + 1);
    }
  }
  if (cache[K] == INF) cout << "-1" << endl;
  else cout << cache[K];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> K;

  cache[0] = 0;
  for (int i = 1; i <= K; ++i) cache[i] = INF;

  for (int i = 0; i < N; ++i) {
    int coin;
    cin >> coin;
    CV.push_back(coin);
  }
  unique(CV.begin(), CV.end());
  solve();
}