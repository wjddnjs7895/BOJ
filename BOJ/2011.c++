//cache[idx] => idx까지 가능한 해석의 수

#include <iostream>
#include <cstring>

using namespace std;

string code;
int cache[5001];

int check(int idx) {
  if (idx + 1 >= code.length() || idx < 0) return 0;
  string temp = "";
  temp += code[idx];
  temp += code[idx + 1];
  int num = stoi(temp);
  if (num <= 26) return 2;
  else return 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  memset(cache, 0, sizeof(cache));

  cin >> code;

  cache[0] = 1;
  if (code[1] == '0') {
    cache[1] = code[0] == '1' || code[0] == '2' ? 1 : -1;
  } else cache[1] = check(1);

  if (cache[1] == -1) {
    cout << 0 << endl;
    return 0;
  }

  for (int i = 2; i < code.length(); ++i) {
    if (code[i] == '0') {
      if (code[i - 1] == '1' || code[i - 1] == '2') {
        cache[i] = cache[i-2];
        continue;
      } else {
        cout << 0 << endl;
        return 0;
      }
    }
    if (check(i - 1) == 2) cache[i] = cache[i - 2] + cache[i - 1];
    else cache[i] = cache[i - 1];
    cache[i] %= 1000000;
  }

  cout << cache[code.length() - 1] << endl;

}