#include <iostream>
#include <cstring>

using namespace std;

int C, N, arr[101][101], cache[101][101];

int func(int y, int x) {
  if (y >= N || x > y) return 0;

  int &ret = cache[y][x];
  if (ret != -1) return ret;


  return ret = arr[y][x] + max(func(y+1, x), func(y+1, x+1));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> C;

  for (int i = 0; i < C; ++i) {
    memset(cache, -1, sizeof(cache));
    cin >> N;
    for (int y = 0; y < N; ++y) {
      for (int x = 0; x <= y; ++x) {
        cin >> arr[y][x];
      }
    }
    cout << func(0,0) << endl;
  }

}