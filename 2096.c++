#include <iostream>
#include <cstring>

#define INF 987654321;
using namespace std;

int a, b, c, N, cache[2][3][2], MAX, MIN;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;

  memset(cache, 0, sizeof(cache));

  for (int y = 0; y < N; ++y) {
    cin >> a >> b >> c;
    cache[(y+1)%2][0][0] = a + max(cache[y%2][0][0],cache[y%2][1][0]);
    cache[(y+1)%2][1][0] = b + max(max(cache[y%2][0][0], cache[y%2][1][0]),cache[y%2][2][0]);
    cache[(y+1)%2][2][0] = c + max(cache[y%2][1][0], cache[y%2][2][0]);
    cache[(y+1)%2][0][1] = a + min(cache[y%2][0][1], cache[y%2][1][1]);
    cache[(y+1)%2][1][1] = b + min(min(cache[y%2][0][1], cache[y%2][1][1]), cache[y%2][2][1]);
    cache[(y+1)%2][2][1] = c + min(cache[y%2][1][1], cache[y%2][2][1]);
  }
  
  MAX = max(max(cache[N%2][0][0], cache[N%2][1][0]), cache[N%2][2][0]);
  MIN = min(min(cache[N%2][0][1], cache[N%2][1][1]), cache[N%2][2][1]);

  cout << MAX << ' ' << MIN << endl;
}