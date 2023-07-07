#include <bits/stdc++.h>

using namespace std;

int N, E, ANS = 0, start;
vector<int> V[51];

void func(int idx) {
  if (idx == E) return;
  bool flag = false;
  for (int i = 0; i < V[idx].size(); ++i) {
    int next = V[idx][i];
    if (next == E) continue;
    flag = true;
    func(next);
  }
  if (!flag) ANS += 1;
}

int main() {
  cin >> N; 
  for (int i = 0; i < N; ++i) {
    int temp;
    cin >> temp;
    if (temp == -1) {
      start = i;
      continue;
    }
    V[temp].push_back(i);
  }
  cin >> E;
  func(start);
  cout << ANS << endl;
}