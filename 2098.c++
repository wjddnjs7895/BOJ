#include <bits/stdc++.h>

using namespace std;

#define INF 987654321;

int n,W[16][16];
int dp[16][1<<16];

int dfs(int cur, int visit){
    
    if (visit == (1<<n)-1){
        if(W[cur][0] == 0)
            return INF;
        return W[cur][0];
    }
    
    if (dp[cur][visit] != -1)
        return dp[cur][visit];
    
    dp[cur][visit] = INF;
    
    for (int i=0; i<n; i++){
        if (W[cur][i]==0)
            continue;
        if ((visit & (1<<i)) == (1<<i)) 
            continue;
        dp[cur][visit] = min(dp[cur][visit], W[cur][i] + dfs(i, visit | 1<<i));
    }
    
    return dp[cur][visit];
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    cin>>n;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin>>W[i][j];
        }
    }
    
    memset(dp, -1, sizeof(dp)); 
    cout<<dfs(0,1);
    
    return 0;
}