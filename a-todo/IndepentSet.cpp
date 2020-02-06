//https://dmoj.ca/problem/dpp
/*
things that made me wa:
using int instead of ll
*/
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;
typedef long long ll;
ll N, dp[100005][2];
const int mod = 1e9+7;

vector<int> adj[100005];
void dfs(int a, int par){
    dp[a][0] = 1; dp[a][1] = 1;
    for(auto e:adj[a]){
        if(e!=par){
            dfs(e, a);
            dp[a][0] = dp[a][0]*dp[e][1]%mod;
            dp[a][1] = dp[a][1]*(dp[e][0]+ dp[e][1])%mod;
        }

    }

}
int main(){
    cin >> N;
    int x, y;
    for(int i=1, x, y;i<N;i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, 0);
    cout << (dp[1][0] + dp[1][1])%mod << "\n";
    return 0;


}