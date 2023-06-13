#include <bits/stdc++.h>

using namespace std;
using pii=pair<int, int>;
int main(){
    int T; cin>>T;
    
    while(T--){
        
        int N, K, W; 
        cin>>N>>K;
        vector<long> spent(N+1, 0); 
        vector<int> vec[N+1];
        vector<int> entry(N+1, 0);
        vector<long> dp(N+1, 0);
        
        for(int i=1; i<=N; i++) cin>>spent[i];
        for(int i=0; i<K; i++){
            int a, b; cin>>a>>b;
            entry[b]++;
            vec[a].push_back(b);
        }
        cin>>W;
        
        queue<int> q;
        for(int i=1; i<=N; i++){
            if(entry[i]==0) {q.push(i); dp[i]=spent[i];}//node, step
        }
        while(!q.empty()){
            int t=q.front(); q.pop();
            int node=t;
            for(int i=0; i<vec[node].size(); i++){
                int nxt=vec[node][i];
                dp[nxt]=max(dp[nxt], dp[node]+spent[nxt]);
                entry[nxt]--;
                if(entry[nxt]==0){
                    q.push(nxt);
                }
            }
        }
        
        cout<<dp[W]<<"\n";
        
    }
    return 0;
}