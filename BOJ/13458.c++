#include <cstring>
#include <iostream>
#include <vector>

typedef long long LL;

using namespace std;

int N, B, C;
LL answer = 0;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;

  vector<int> VA(N);

  for (int i = 0; i < N; ++i) {
    cin >> VA[i];
  }
  cin >> B >> C;

  for (int i = 0; i < N; ++i) {
    answer += 1;
    if (VA[i] - B > 0) answer += ((VA[i] - B) / C);
    if (VA[i] - B > 0 && (VA[i] - B) % C != 0) answer += 1;
  }
  cout << answer << endl;
}