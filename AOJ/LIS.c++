#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int C, N, cache[501], MAX;
vector<int> V;

int maxLen(int idx) {
  int& ret = cache[idx];
  for(int i = 0; i < idx; ++i) {
    if (V[i] < V[idx]) {
      ret = max(cache[i] + 1, ret);
    }
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> C;

  for (int i = 0; i < C; ++i) {
    cin >> N;
    MAX =  0;
    V.clear();
    for (int j = 0; j < N; ++j) {
      int temp;
      cin >> temp;
      V.push_back(temp);
      cache[j] = 1;
      MAX = max(maxLen(j), MAX);
    }
    cout << MAX << endl;
  }
}