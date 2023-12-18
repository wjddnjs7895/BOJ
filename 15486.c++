#include <bits/stdc++.h>

using namespace std;

int N, cache[1500001], MAX_ANS = 0;
vector<pair<int,int>> V;

int getMaxProfit(int idx) {
  if (idx >= N) return 0;
  int& ret = cache[idx];
  if (ret != -1) return ret;
  int t = V[idx].first;
  int p = V[idx].second;
  if (idx + t <= N) return ret = max(getMaxProfit(idx+t)+p, getMaxProfit(idx+1));
  else return ret = getMaxProfit(idx+1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  memset(cache, -1, sizeof(cache));

  cin >> N; 

  for (int i = 0; i < N; ++i) {
    int t, p;
    cin >> t >> p;
    V.push_back({t,p});
  }
  for (int i = 0; i < N; ++i) {
    MAX_ANS = max(getMaxProfit(i), MAX_ANS);
  }
  cout << MAX_ANS << endl;
}