#include <iostream>
#include <cstring>

using namespace std;

int N;

pair<int,int> getPreNumLen(int num) {
  int pNum = 0, length = 3;
  while (length < num) {
    int temp;
    temp = length * 2 + pNum + 4;
    if (temp < num) {
      pNum++;
      length = temp;
    } else break;
  }
  return {pNum, length};
}

void solve(int num) {
  if (num == 1) {
    cout << 'm' << endl;
    return;
  } else if (N <= 3) {
    cout << 'o' << endl;
    return;
  }
  pair<int,int> pNumLen = getPreNumLen(num);
  int pNum = pNumLen.first;
  int pLen = pNumLen.second;
  if (pLen == num) cout << 'o' << endl;
  else if (pLen + 1 == num) cout << 'm' << endl;
  else if (pLen + pNum + 5 == num) cout << 'm' << endl;
  else {
    solve(num - pLen - pNum - 4);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  solve(N);
}