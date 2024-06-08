#include <iostream>
#include <cstring>

#define MOD 1000000007

typedef long long LL;

using namespace std;

int N;
LL cache[4];
string S;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> S;

  memset(cache, 0, sizeof(cache));

  for (int idx = 0; idx < N; ++idx) {
    char sc = S[idx];
    if (sc == 'W') cache[0] = (cache[0] + 1)%MOD;
    else if (sc == 'H') cache[1] = (cache[1] + cache[0])%MOD;
    else if (sc == 'E'){
      cache[3] = (cache[3] + cache[2])%MOD;
      cache[2] = (cache[2] + cache[1] + cache[2])%MOD;
    }
  }

  cout << cache[3] << endl;
}