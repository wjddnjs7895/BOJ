#include <bits/stdc++.h>

using namespace std;

long long N;
int cache[1500001];

int fibo(long long n) {
  if (n == 0 || n == 1) return n;
  int& ret = cache[n];
  if (ret != -1) return ret;

  return ret = (fibo(n - 1) + fibo(n - 2)) % 1000000;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  memset(cache, -1, sizeof(cache));

  cin >> N;
  cout << fibo(N % 1500000) << endl;
  return 0;
}