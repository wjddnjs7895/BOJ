#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int N, M, K, candyArr[30001], MAX_ANS = 0, counting = 0, cache[30001];
vector<int> graphV[30001];
vector<pair<int,int>> countV;
bool visited[30001];

int dfs(int idx) {
  int candySum = 0;
  visited[idx] = true;
  counting += 1;
  for (int i = 0; i < graphV[idx].size(); ++i) {
    int next = graphV[idx][i];
    if (!visited[next]) candySum +=  dfs(next);
  }
  return candySum + candyArr[idx];
}

void func() {
  int ans = 0; 
  cache[0] = 0;
  for (int idx = 0; idx < countV.size(); idx++) {
    int child = countV[idx].first;
    int candy = countV[idx].second;
    for (int i = K - 1; i >= 0; i--) {
      if (i - child >= 0) {
        cache[i] = max(cache[i], cache[i - child] + candy);
        ans = max(ans, cache[i]);
      }
    }
  }
  MAX_ANS = ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  memset(cache, -1, sizeof(cache));

  cin >> N >> M >> K;
  for (int i = 1; i <= N; ++i) {
    cin >> candyArr[i];
  }
  for (int i = 0; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    graphV[a].push_back(b);
    graphV[b].push_back(a);
  }
  for (int i = 1; i <= N; ++i) {
    if (!visited[i]) {
      counting = 0;
      int candy = dfs(i);
      if (counting < K) countV.push_back({counting, candy});
    }
  }
  func();
  cout << MAX_ANS << endl;
}