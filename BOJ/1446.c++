#include <iostream>
#include <cstring>
#include <vector>

#define INF 987654321

using namespace std;

int N, D, cache[10001];
vector<pair<int,int>> arr[10001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> D;

  for (int i = 0; i <= D; ++i) {
    vector<pair<int, int>> tempV;
    arr[i] = tempV;
    cache[i] = INF;
  }

  for (int i = 0; i < N; ++i) {
    int start, end, distance;
    cin >> start >> end >> distance;
    arr[start].push_back({end, distance});
  }

  cache[0] = 0;
  for (int pos = 0; pos <= D; ++pos) {
    cache[pos + 1] = min(cache[pos] + 1, cache[pos+1]);
    for (int i = 0; i < arr[pos].size(); ++i) {
      int end = arr[pos][i].first;
      int distance = arr[pos][i].second;
      cache[end] = min(cache[end], cache[pos] + distance);
    }
  }

  cout << cache[D] << endl;
}