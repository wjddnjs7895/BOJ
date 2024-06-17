#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N, M, cache[41], vipIdx = 0, max_idx = 0, answer = 1;
vector<int> arr;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> M;
  
  if (M == 0) {
    arr.push_back(N);
    max_idx = N;
  }
  for (int i = 0; i < M; ++i) {
    int temp = vipIdx;
    cin >> vipIdx;
    arr.push_back(vipIdx - temp - 1);
    max_idx = max(max_idx, vipIdx - temp - 1);
    if (i == M - 1) {
      arr.push_back(N - vipIdx); 
      max_idx = max(max_idx, N - vipIdx);
    }
  }
  cache[0] = 1;
  cache[1] = 1;
  for (int i = 2; i <= max_idx; ++i) {
    cache[i] = cache[i-1] + cache[i-2];
  }

  for (int i = 0; i < arr.size(); ++i) answer *= cache[arr[i]];

  cout << answer << endl;
}