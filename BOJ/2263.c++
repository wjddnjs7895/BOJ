#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N;
vector<int> inorder, postorder;

void func(int inIdx, int postIdx, int size) {
  if (size < 1) return;
  if (size == 1) {
    cout << inorder[inIdx] << ' ';
    return;
  }
  int root = postorder[postIdx + size - 1];
  for (int i = 0; i < size; ++i) {
    if (inorder[inIdx + i] == root) {
      func(inIdx + i, size - 1, 1);
      func(inIdx, postIdx, i);
      func(inIdx + i + 1, postIdx + i, size - i - 1);
      return;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;

  int temp;
  for (int i = 0; i < N; ++i) {
    cin >> temp;
    inorder.push_back(temp);
  }
  for (int i = 0; i < N; ++i) {
    cin >> temp;
    postorder.push_back(temp);
  }
  func(0, 0, N);
}