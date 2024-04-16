#include <iostream>
#include <cstring>

using namespace std;

int X, N, cost = 0;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> X;
  cin >> N;

  for (int i = 0; i < N; ++i) {
    int c, n;
    cin >> c >> n;
    cost += c * n;
  }

  if (cost == X) cout << "Yes" << endl;
  else cout << "No" << endl;
}