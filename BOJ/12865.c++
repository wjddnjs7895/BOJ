#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<pair<int, int>> V;
int cache[101][100001];


int func(int n, int k) {
    int& ret = cache[n][k];
    if (n == N) return 0;
    if (ret != -1) return ret;
    if (k >= V[n].first) return ret = max(func(n+1, k), func(n+1,k-V[n].first) + V[n].second); 
    else return ret = func(n+1, k);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    memset(cache, -1, sizeof(cache));
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        int w, v;
        cin >> w >> v;
        V.push_back({w, v});
    }
    V.push_back({0,0});\
    cout << func(0, K) << endl;
    return 0;
}
