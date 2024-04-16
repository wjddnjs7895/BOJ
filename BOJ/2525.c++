#include <iostream>
#include <cstring>

using namespace std;

int A, B, C;

void solve(int a, int b) {
  a += b/60;
  a %= 24;
  b %= 60;
  cout << a << ' ' << b << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> A >> B;
  cin >> C;

  solve(A, B + C);
}