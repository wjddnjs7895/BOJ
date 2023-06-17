#include <bits/stdc++.h>

using namespace std;

int N, S, MIN = 987654321;
vector<int> V;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> S;
  for (int i = 0; i < N; ++i) {
    int temp;
    cin >> temp;
    V.push_back(temp);
  }
  int startIdx = 0, endIdx = -1, SUM = 0;
  while (startIdx < N && endIdx < N) {
    if (SUM >= S) {
      MIN = min(MIN, endIdx - startIdx + 1);
      SUM -= V[startIdx];
      startIdx += 1;
    } else {
      endIdx += 1;
      SUM += V[endIdx];
    }
  }
  if (MIN == 987654321) cout << '0' << endl;
  else cout << MIN << endl;
}