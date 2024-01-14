#include <bits/stdc++.h>

using namespace std;

int N;
priority_queue<int> PQ_FRONT;
priority_queue<int, vector<int>, greater<int>> PQ_BACK;

int func(int num) {
    if (PQ_FRONT.empty()) {
        PQ_FRONT.push(num);
        return num;
    }
    if (PQ_FRONT.top() > num) {
        if (PQ_FRONT.size() <= PQ_BACK.size()) PQ_FRONT.push(num);
        else {
            PQ_BACK.push(PQ_FRONT.top());
            PQ_FRONT.pop();
            PQ_FRONT.push(num);
        }
    } else {
        if (PQ_FRONT.size() <= PQ_BACK.size()) {
            if (PQ_BACK.top() < num) {
                PQ_FRONT.push(PQ_BACK.top());
                PQ_BACK.pop();
                PQ_BACK.push(num);
            } else {
                PQ_FRONT.push(num);
            }
        }
        else {
            PQ_BACK.push(num);
        }
    }

    return PQ_FRONT.top();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        cout << func(num) << '\n';
    }
    return 0;
}