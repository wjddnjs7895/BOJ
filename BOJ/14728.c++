#include <iostream>
#include <cstring>
#include <vector>

#define INF 987654312

using namespace std;

int N, T, K, S, cache[10001][101];
vector<pair<int,int>> V;

int recur(int remain, int idx) {
  if (remain < 0) return -INF;
  if (idx == N) return 0;
  
  int& ret = cache[remain][idx];
  if(ret != -1) return ret;

  int time = V[idx].first;
  int score = V[idx].second;
  return ret = max(recur(remain - time, idx + 1) + score, recur(remain, idx + 1));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> N >> T;

  memset(cache, -1, sizeof(cache));

  for (int i = 0; i < N; ++i) {
    cin >> K >> S;
    V.push_back({K, S});
  }
  recur(T, 0);

  cout << cache[T][0] << endl;
}