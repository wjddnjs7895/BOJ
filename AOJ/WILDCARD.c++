#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int C, N, cache[101][101];
string patternStr, fileName;

bool func(int ptnIdx, int strIdx) {
  if (ptnIdx == patternStr.length() && strIdx == fileName.length()) return true;
  if (ptnIdx >= patternStr.length()) return false;
  if (strIdx >= fileName.length()) return patternStr[ptnIdx] == '*' && func(ptnIdx + 1, strIdx);
  
  int& ret = cache[ptnIdx][strIdx];
  if (ret != -1) return ret;

  char ptnChar, strChar;
  ptnChar = patternStr[ptnIdx];
  strChar = fileName[strIdx];

  if (ptnChar == '?') return ret = func(ptnIdx + 1, strIdx + 1);
  else if (ptnChar == '*') return ret = func(ptnIdx + 1, strIdx) || func(ptnIdx, strIdx + 1) || func(ptnIdx + 1, strIdx + 1);
  else return ret = ptnChar == strChar && func(ptnIdx + 1, strIdx + 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> C;

  for (int i = 0; i < C; ++i) {
    cin >> patternStr;
    cin >> N;
    vector<string> strV;
    for (int j = 0; j < N; ++j) {
      memset(cache, -1, sizeof(cache));
      cin >> fileName;
      if(func(0, 0)) strV.push_back(fileName);
    }
    sort(strV.begin(), strV.end());
    for (int j = 0; j < strV.size(); ++j) cout << strV[j] << endl;
  }
}