#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
#define f first
#define s second
typedef pair<int, int> pi;
typedef long long lld;
const lld mod = 1e9+7, mx= 3e5+2;
vector<vector<pi>> adj; vector<pi> val;
int N, M, K, lo, hi;
bool vis[mx], vis2[mx];
int rep(int v){
    vis[v] = true;
    for(auto e:adj[v]){
        int u = e.f, c = e.s;
        
        if(!vis[u]){
            val[u] = {-val[v].f,c-val[v].s};
            rep(u);
        }
    }
}
int dfs(int v){
    vis2[v] = true;
    if(val[v].f==-1){
        lo = max(1, val[v].s-hi);
    }
}
int main(){
    scanf("%d %d %d", &N, &M, &K);
    adj.resize(N+1);
    val.resize(N+1);
    for(int i=0;i<N;i++){
        int a, b, c;
        scanf("%d %d %d", a, b, c);
        adj[a].push_back({b, c}); adj[b].push_back({a, c});
    }
    for(int i=1;i<=N;i++){
        if(!vis[i]){
            val[i]= {1, 0};
            rep(i);
            lo = 1; hi=K;
            dfs(i);

        }
    }
} 