#include <bits/stdc++.h>

using namespace std;

int N, P, maxLength, minCost = 51;
string maxString;
vector<pair<int,int>> V;

void func(string snum, int capacity) {
  for (int i = 0; i < maxLength; i++) {
    for (int idx = N-1; idx >= 0; --idx) {
      if (V[idx].first <= capacity+minCost) {
        capacity += minCost;
        capacity -= V[idx].first;
        snum[i] = '0'+V[idx].second;
        break;
      }
    }
  }
  maxString = snum;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; ++i) {
    int temp;
    cin >> temp;
    minCost = min(temp, minCost);
    V.push_back({temp, i});
  }
  cin >> P;
  maxLength = P/minCost;
  maxString = "";
  for (int i = 0; i < maxLength; ++i) maxString += '0';
  func(maxString, P - minCost*maxLength);
  while (maxString[0] == '0' && maxLength != 1) {
    maxLength -= 1;
    maxString = "";
    for (int i = 0; i < maxLength; ++i) maxString += '0';
    func(maxString, P-minCost*maxLength);
  }
  cout << maxString << endl;
}