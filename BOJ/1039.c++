#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

string N;
bool visited[1000001];
int K, MAX = -1;

void bfs() {
  queue<pair<string,int>> Q;
  Q.push({N, 0});

  while(!Q.empty()) {
    string cn = Q.front().first;
    int cnt = Q.front().second;
    Q.pop();

    if (visited[stoi(cn)]) continue;
    if ((K - cnt) % 2 == 0 && cnt != 0) {
      MAX = max(MAX, stoi(cn));
      visited[stoi(cn)] = true;
    }
    if (cnt == K) continue;

    for (int idx1 = 0; idx1 < N.length() - 1; ++idx1) {
      for (int idx2 = idx1 + 1; idx2 < N.length(); ++idx2) {
        if (idx1 == 0 && cn[idx2] == '0') continue;
        string tempcn = cn;
        char tempc = tempcn[idx1];
        tempcn[idx1] = tempcn[idx2];
        tempcn[idx2] = tempc;
        Q.push({tempcn, cnt + 1});
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  memset(visited, 0, sizeof(visited));

  cin >> N >> K;
  bfs();
  cout << MAX << endl;
}