#include <bits/stdc++.h>

using namespace std;

string S1, S2, SR;
int cache[1002][1002];

int LCS(int y, int x) {
  int& ret = cache[y][x];
  if (ret != -1) return ret;

  char c1 = S1[x-1];
  char c2 = S2[y-1];
  if (c1 != c2) return ret = max(LCS(y,x-1), LCS(y-1,x));
  else return ret = max(LCS(y-1,x-1) + 1, LCS(y-1,x));
}

void restore(int y, int x) {
  if (x == 0 || y == 0) return;
  if (cache[y][x] == cache[y][x-1]) return restore(y, x-1);
  else if (cache[y][x] == cache[y-1][x-1] + 1 && S2[y-1] == S1[x-1]) {
    SR += S2[y-1];
    return restore(y-1,x-1);
  }
  return restore(y-1,x);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  memset(cache,-1,sizeof(cache));

  cin >> S1 >> S2;
  for (int i = 0; i <= S1.length(); ++i) cache[0][i] = 0;
  for (int i = 0; i <= S2.length(); ++i) cache[i][0] = 0;
  for (int y = 1; y <= S2.length(); ++y)
    for (int x = 1; x <= S1.length(); ++x)
      LCS(y,x);
  cout << cache[S2.length()][S1.length()] << endl;
  if (cache[S2.length()][S1.length()] != 0) {
    restore(S2.length(), S1.length());
    for (int i = SR.length() - 1; i >= 0; --i) cout << SR[i];
  }
}