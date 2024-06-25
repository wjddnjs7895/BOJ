#include <iostream>

using namespace std;

int N, X, answer = 0;

int solve(int length) {
  int temp = 1, result = 1;
  while (temp < length) {
    result = 2 * result + 1;
    temp = 2 * temp + 3;
  }
  return result;
}

void recur(int length, int counting) {
  cout << "length : " << length << " / counting : " << counting << endl;
  if (counting <= 1) {
    cout << answer << endl;
    return;
  } else if (counting == length) {
    answer += solve(length);
  }
  int preLength = (length - 3)/2;
  if (counting > preLength + 2) {
    recur(preLength, counting - 1);
  } else if (counting == preLength + 2) {
    recur(preLength + 2, counting);
  } else {
    answer += solve(preLength);
    recur(preLength, counting - preLength - 2);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> X;

  int length = 1;
  while (1) {
    length = 2 * length + 3;
    if (length > X) {
      length = (length - 3)/2;
      break;
    }
    answer += 2 * answer + 1;
  }

  recur(length, X - length);
}