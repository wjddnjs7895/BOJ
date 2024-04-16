#include <iostream>
#include <cstring>

using namespace std;

int N;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> N;

  for (int i = 0; i < N/4; ++i) cout << "long ";

  cout << "int" << endl;
}