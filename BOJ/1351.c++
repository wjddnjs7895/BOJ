#include <iostream>
#include <cstring>
#include <unordered_map>

typedef long long LL;

using namespace std;

LL N, P, Q;
unordered_map<LL, LL> cache;

LL solve(LL num) {
  LL& ret = cache[num];
  if (ret != 0) return ret;

  LL idx1 = num/P;
  LL idx2 = num/Q;
  return ret = solve(idx1) + solve(idx2);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> P >> Q;
  cache[0] = 1;
  
  cout << solve(N) << endl;
}