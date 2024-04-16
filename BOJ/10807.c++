#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, X, result = 0;
vector<int> NV;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; ++i) {
    int temp;
    cin >> temp;
    NV.push_back(temp);
  }

  cin >> X;
  for (int i = 0; i < NV.size(); ++i) {
    if (NV[i] == X) result += 1;
  }
  cout << result << endl;
}