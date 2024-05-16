#include <iostream>
#include <cstring>

using namespace std;

string code;
int cache[5001];

void solve() {
  for (int idx = 0; idx < code.length(); ++idx) {
    int temp;
    if (idx >= 1) {
      string str = "";
      str += code[idx-1];
      str += code[idx];
      if (stoi(str) >= 10 && stoi(str) <= 26) cache[idx + 1] += cache[idx-1];
    }
    if (code[idx] != '0') cache[idx + 1] += cache[idx];
    cache[idx + 1] %= 1000000;
  }
  cout << cache[code.length()];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  memset(cache, 0, sizeof(cache));
  cache[0] = 1;

  cin >> code;
  
  solve();
}