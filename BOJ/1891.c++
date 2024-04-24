#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

int D;
ll X, Y;
string numStr;

pair<pair<ll,ll>,pair<ll,ll>> num2pos(string str) {
  ll totalLen = 1ll << D;
  ll minX = -totalLen/2, minY = -totalLen/2;
  ll maxX = totalLen/2, maxY = totalLen/2;
  for (int i = 0; i < D; ++i) {
    ll halfX = (minX + maxX)/2;
    ll halfY = (minY + maxY)/2;
    if (str[i] == '1') {
      minX = halfX;
      minY = halfY;
    } else if (str[i] == '2') {
      maxX = halfX;
      minY = halfY;
    } else if (str[i] == '3') {
      maxX = halfX;
      maxY = halfY;
    } else {
      minX = halfX;
      maxY = halfY;
    }
  }
  return {{minX, maxX}, {minY, maxY}};
}

string pos2num(ll minX, ll maxX, ll minY, ll maxY) {
  ll totalLen = 1ll << (D - 1);
  ll dx[4] = {-1, 1, 1, -1};
  ll dy[4] = {-1, -1, 1, 1};
  string resultStr = "";
  for (int i = 0; i < D; ++i) {
    int dim = 0;
    if (minX >= 0 && minY >= 0) dim = 1;
    else if (minX < 0 && minY >= 0) dim = 2;
    else if (minX < 0 && minY < 0) dim = 3;
    else dim = 4;
    resultStr += to_string(dim);
    minX += dx[dim - 1] * totalLen/2;
    maxX += dx[dim - 1] * totalLen/2;
    minY += dy[dim - 1] * totalLen/2;
    maxY += dy[dim - 1] * totalLen/2;
    totalLen /= 2;
  }
  return resultStr;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> D >> numStr;
  cin >> X >> Y;
  pair<pair<ll,ll>, pair<ll,ll>> pos = num2pos(numStr);
  ll minX = pos.first.first, maxX = pos.first.second, minY = pos.second.first, maxY = pos.second.second;
  minX += X;
  maxX += X;
  minY += Y;
  maxY += Y;
  ll halfLength = 1ll << (D - 1);

  if (minX < -halfLength || maxX > halfLength || minY < -halfLength || maxY > halfLength) cout << "-1" << endl;
  else cout << pos2num(minX, maxX, minY, maxY) << endl;
}