#include <iostream>
#include <cstring>

using namespace std;

int N, R, C;

int recur(int y, int x, int gy, int gx, int length) {
  if (y == gy && x == gx) return 0;
  int nlength = length/2;
  int counting = nlength * nlength;
  if (gy < nlength && gx < nlength) return recur(y/2, x/2, gy, gx, nlength);
  else if (gy < nlength && gx >= nlength) return counting + recur(y/2, x/2+nlength, gy, gx-nlength, nlength);
  else if (gy >= nlength && gx < nlength) return counting * 2 + recur(y/2+nlength, x/2, gy-nlength, gx, nlength);
  else return counting * 3 + recur(y/2+nlength, x/2+nlength, gy-nlength, gx-nlength, nlength);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> R >> C;

  cout << recur(1 << N,1 << N, R, C, 1 << N) << endl;
}