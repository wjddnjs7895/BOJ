#include <iostream>
#include <cstring>

using namespace std;

int N, length = 3, midLength = 4;
string str = "moo";

void recur(int totalLen, int midLen, int num) {
  if (totalLen <= 3) str[num - 1];
  int preLen = (totalLen - midLen) / 2;
  if (num <= preLen) recur(preLen, midLen - 1, num);
  else if (num <= preLen + midLen) {
    if (num - preLen == 1) cout << 'm' << endl;
    else cout << 'o' << endl;
  } else recur(preLen, midLen - 1, num - preLen - midLen);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;

  while (length < N) {
    length = length * 2 + midLength;
    midLength++;
  }
  recur(length, midLength - 1, N);
}