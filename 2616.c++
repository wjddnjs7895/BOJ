#include <iostream>

using namespace std;
int ps[50001] = {0,};
int dp[4][50001] = {0,};
int result = 0;

int main(){
    int n, k, tmp;
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> tmp;
        //누적합
        ps[i] = ps[i-1] + tmp;
    }

    cin >> k;
	\
    for(int i = 1; i <= 3; i++){\
        for(int j = i * k; j <= n; j++){
                dp[i][j] = max(dp[i][j-1], dp[i-1][j-k] + ps[j] - ps[j-k]);
        }
    }

    cout << dp[3][n] << endl;
    return 0;
}