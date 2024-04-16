#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int a, b, c;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> a >> b >> c;

  if (a == b && b == c) cout << 10000 + a * 1000 << endl;
  else if (a == b) cout << 1000 + a * 100 << endl;
  else if (b == c) cout << 1000 + b * 100 << endl;
  else if (c == a) cout << 1000 + c * 100 << endl;
  else cout << max(a, max(b, c)) * 100 << endl;
}