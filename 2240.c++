#include <bits/stdc++.h>

using namespace std;

int T, W, cache[31][1001], arr[1001], MAX_ANS = 0;

int getMaxFruit(int counting, int time) {
  int fruitSuccess = (int)(arr[time] == counting % 2 + 1);
  if (time == 0) return fruitSuccess ;
  int& ret = cache[counting][time];
  if (ret != -1) return ret;
  if (counting == W) return ret = getMaxFruit(counting, time-1) + fruitSuccess;
  else return ret = max(getMaxFruit(counting+1, time - 1), getMaxFruit(counting, time - 1)) + fruitSuccess;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  memset(cache, -1, sizeof(cache));

  cin >> T >> W;

  for (int i = 0; i < T; ++i) {
    cin >> arr[i];
  }
  for (int c = 0; c <= W; ++c) {
    MAX_ANS = max(getMaxFruit(c, T-1), MAX_ANS);
  }
  cout << MAX_ANS << endl;
}