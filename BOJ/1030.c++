#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int S, N, K, R1, R2, C1, C2, arr[50][50];

void check_print(int x, int y, int color) {
  if (y >= R1 && y <= R2 && x >= C1 && x <= C2) {
    arr[y-R1][x-C1] = color;
  }
}

void func(int floor, int posX, int posY, int color) {
  int unit = pow(N, S-floor)/N;
  if (floor == S) {
    check_print(posX, posY, color);
    return;
  }
  if (posY + unit*N < R1 || posX + unit*N < C1 || posY > R2 || posX > C2) return;
  for (int y = 0; y < N; ++y) {
    for (int x = 0; x < N; ++x) {
      if (color == 1)
        func(floor + 1, posX + x * unit, posY + y * unit, 1);
      else if (y >= (N-K)/2 && y < (N+K)/2 && x >= (N-K)/2 && x < (N+K)/2)
        func(floor + 1, posX + x * unit, posY + y * unit, 1);
      else func(floor + 1, posX + x * unit, posY + y * unit, 0);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> S >> N >> K >> R1 >> R2 >> C1 >> C2;
  func(0, 0, 0, 0);

  for (int y = 0; y <= R2 - R1; ++y) {
    for (int x = 0; x <= C2 - C1; ++x) {
      cout << arr[y][x];
    }
    cout << endl;
  }
}