#include <bits/stdc++.h>

using namespace std;

int N, H, W;
char board[103][103];
deque<pair<pair<int,int>,int>> DQ;
vector<pair<int,int>> SV;
int num_board[3][103][103];

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

void bfs(int level) {
  while (!DQ.empty()) {
    int y = DQ.front().first.first;
    int x = DQ.front().first.second;
    int st = DQ.front().second;
    num_board[level][y][x] = st;
    DQ.pop_front();
    for (int i = 0; i < 4; ++i) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny < 0 || ny > H + 1 || nx < 0 || nx > W + 1 || num_board[level][ny][nx] != -1) continue;
      if (board[ny][nx] == '*') continue;
      else if (board[ny][nx] == '#') DQ.push_back({{ny, nx}, st + 1});
      else DQ.push_front({{ny, nx}, st});
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  for (int i = 0; i < N; ++i) {
    int MIN = 12345;
    memset(num_board, -1, sizeof(num_board));
    DQ = deque<pair<pair<int,int>,int>>();
    SV = vector<pair<int,int>>();
    cin >> H >> W;
    for (int y = 1; y <= H; ++y) {
      for (int x = 1; x <= W; ++x) {
        cin >> board[y][x];
        if (board[y][x] == '$') SV.push_back({y,x});
      }
    }
    DQ.push_back({{0,0},0});
    bfs(0);
    DQ.push_back({SV[0],0});
    bfs(1);
    DQ.push_back({SV[1],0});
    bfs(2);

    for (int y = 0; y <= H + 1; ++y) {
      for (int x = 0; x <= W + 1; ++x) {
        int sum_num = num_board[0][y][x] + num_board[1][y][x] + num_board[2][y][x];
        if (board[y][x] == '#') {
          sum_num -= 2;
        }
        if (sum_num != -3) MIN = min(MIN, sum_num);
      }
    }
    cout << MIN << endl;
  }
}