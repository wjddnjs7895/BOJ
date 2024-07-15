#include <iostream>
#include <cstring>
#include <queue>

#define MAX 2002

using namespace std;

int S;
bool visited[MAX][MAX];
queue<pair<pair<int,int>,int>> Q;

int bfs() {
  Q.push({{1, 0}, 0});
  visited[1][0] = true;
  while (!Q.empty()) {
    int idx = Q.front().first.first;
    int clip = Q.front().first.second;
    int time = Q.front().second;

    Q.pop();

    if (idx == S) return time;

    if (!visited[idx][idx]) {
      visited[idx][idx] = true;
      Q.push({{idx, idx}, time + 1});
    }

    if (idx + clip < MAX && !visited[idx + clip][clip]) {
      visited[idx + clip][clip] = true;
      Q.push({{idx + clip, clip},time + 1});
    }

    if (idx > 0 && !visited[idx - 1][clip]) {
      visited[idx - 1][clip] = true;
      Q.push({{idx - 1, clip}, time + 1});
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> S;

  int answer = bfs();
  cout << answer << endl;
}