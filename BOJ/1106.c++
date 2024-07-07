#include <iostream>
#include <cstring>

#define INF 987654321

using namespace std;

int C, N, cache[1101], answer = INF;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> C >> N;
  
  for (int i = 0; i <= C + 100; ++i) cache[i] = INF;
  cache[0] = 0;

  for (int i = 0; i < N; ++i) {
    int cost, num;
    cin >> cost >> num;

    for (int idx = 0; idx <= C + 100; ++idx) {
      if (idx - num < 0 || cache[idx - num] == INF) continue;
      cache[idx] = min(cache[idx], cache[idx-num] + cost);
      if (idx >= C) answer = min(answer, cache[idx]);
    }
  }

  cout << answer << endl;
}