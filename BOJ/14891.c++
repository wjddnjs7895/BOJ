#include <cstring>
#include <iostream>

using namespace std;

int K, arr[5][8], idxArr[5], answer = 0;

void rotate(int startIdx, int dir) {
  int nextIdxArr[5];
  for (int i = 1; i < 5; ++i) nextIdxArr[i] = idxArr[i];

  int left = startIdx;
  int leftDir = dir;
  int right = startIdx;
  int rightDir = dir;

  if (dir == 1) {
    nextIdxArr[startIdx] = (idxArr[startIdx] + 7) % 8;
  } else if (dir == -1) {
    nextIdxArr[startIdx] = (idxArr[startIdx] + 1) % 8;
  }

  while (left > 0 || right <= 4) {
    if (left - 1 > 0) {
      if (arr[left - 1][(idxArr[left - 1] + 2) % 8] !=
          arr[left][(idxArr[left] + 6) % 8]) {
        if (leftDir == 1) {
          nextIdxArr[left - 1] = (idxArr[left - 1] + 1) % 8;
        } else if (leftDir == -1) {
          nextIdxArr[left - 1] = (idxArr[left - 1] + 7) % 8;
        }
        leftDir *= -1;
      } else
        left -= 4;
    }
    left -= 1;
    if (right + 1 <= 4) {
      if (arr[right + 1][(idxArr[right + 1] + 6) % 8] !=
          arr[right][(idxArr[right] + 2) % 8]) {
        if (rightDir == 1) {
          nextIdxArr[right + 1] = (idxArr[right + 1] + 1) % 8;
        } else if (rightDir == -1) {
          nextIdxArr[right + 1] = (idxArr[right + 1] + 7) % 8;
        }
        rightDir *= -1;
      } else
        right += 4;
    }
    right += 1;
  }
  for (int i = 1; i < 5; ++i) {
    idxArr[i] = nextIdxArr[i];
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  for (int i = 0; i < 5; ++i) idxArr[i] = 0;

  for (int i = 1; i <= 4; ++i) {
    string str;
    cin >> str;
    for (int j = 0; j < 8; ++j) arr[i][j] = str[j] - '0';
  }

  cin >> K;

  for (int i = 0; i < K; ++i) {
    int num, dir;
    cin >> num >> dir;
    rotate(num, dir);
  }

  for (int i = 1; i < 5; ++i) {
    answer += (arr[i][idxArr[i]] << (i - 1));
  }

  cout << answer << endl;
}