#include <iostream>
#include <cstring>

#define INF 987654321

using namespace std;

int N, cache[100001];

int recur(int cost) {
  if (cost == 0) return 0;
  else if (cost < 0) return INF;

  int& ret = cache[cost];
  if (ret != -1) return ret;
  return ret = min(recur(cost - 2), recur(cost - 5)) + 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  memset(cache, -1, sizeof(cache));

  cin >> N;
  
  int result = recur(N);
  if (result >= INF) cout << "-1" << endl;
  else cout << result << endl;
}