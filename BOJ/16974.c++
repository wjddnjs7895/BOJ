#include <iostream>

using namespace std;

typedef long long LL;

LL N, X;
LL answer = 0;

LL solve(LL length) {
  LL temp = 1, result = 1;
  while (temp < length) {
    result = 2 * result + 1;
    temp = 2 * temp + 3;
  }
  return result;
}

void recur(LL length, LL counting) {
  if (length == 1) {
    if (counting > 0) answer += 1;
    return;
  }
  LL preLength = (length - 3)/2;
  if (counting < preLength + 2) {
    recur(preLength, counting - 1);
  } else if (counting == preLength + 2) {
    answer += (solve(preLength) + 1);
  } else {
    answer += (solve(preLength) + 1);
    recur(preLength, counting - preLength - 2);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> X;

  LL length = 1;
  for (int i = 0; i < N; ++i) {
    length = 2 * length + 3;
  }

  recur(length, X);

  cout << answer << endl;
}