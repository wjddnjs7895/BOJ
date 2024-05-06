#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int T, N;
vector<int> preorder, inorder;

void func(int preIdx, int inIdx, int size) {
  if (size < 1) return;
  if (size == 1) {
    cout << preorder[preIdx] << ' ';
    return;
  }
  int root = preorder[preIdx];
  for (int i = 0; i < size; ++i) {
    if (inorder[inIdx + i] == root) {
      func(preIdx + 1, inIdx, i);
      func(preIdx + i + 1, inIdx + i + 1, size - i - 1);
      func(preIdx, inIdx + i, 1);
      return;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> T;
  for (int i = 0; i < T; ++i) {
    preorder.clear();
    inorder.clear();
    cin >> N;
    int temp;
    for (int j = 0; j < N; ++j) {
      cin >> temp;
      preorder.push_back(temp);
    }
    for (int j = 0; j < N; ++j) {
      cin >> temp;
      inorder.push_back(temp);
    }
    func(0, 0, N);
    cout << endl;
  }
}