#include <bits/stdc++.h>

using namespace std;

string str, targetStr, tempStr;
int cache[1000002], targetLen;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  memset(cache, -1, sizeof(cache));

  cin >> str >> targetStr;
  targetLen = targetStr.length();
  for (int idx = 0; idx < str.length(); ++idx) {
    tempStr += str[idx];
    int tempLen = tempStr.length();
    if (tempLen >= targetLen && tempStr[tempLen - 1] == targetStr[targetLen - 1]) {
      for (int i = 0; i < targetLen; ++i) {
        if (tempStr[tempLen - 1 - i] != targetStr[targetLen - 1 - i]) break;
        if (i == targetLen - 1) {
          for (int j = 0; j < targetLen; ++j) tempStr.pop_back();
        }
      }
    }
  }
  if (tempStr.length() == 0) cout << "FRULA" << endl;
  else  cout << tempStr << endl;
}