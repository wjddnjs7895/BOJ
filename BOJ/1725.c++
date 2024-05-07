#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N;
vector<int> V;

int func(int left, int right) {
  if (left == right) return V[left];

  int mid = (left + right) / 2;
  int tempLeft = mid, tempRight = mid+1;
  int height = min(V[tempLeft], V[tempRight]);
  int ret = height * 2;
  ret = max(ret, max(func(left, mid), func(mid+1, right)));

  while (tempLeft > left || tempRight < right) {
    if (tempLeft == left || V[tempLeft - 1] < V[tempRight + 1]) {
      tempRight += 1;
      height = min(height, V[tempRight]);
    } else {
      tempLeft -= 1;
      height = min(height, V[tempLeft]);
    } 
    ret = max(ret, (tempRight - tempLeft + 1) * height);
  }

  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;

  int temp;

  for (int i = 0; i < N; ++i) {
    cin >> temp;
    V.push_back(temp);
  }

  cout << func(0, N-1);;
}