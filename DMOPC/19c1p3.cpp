#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef pair<int, int> pi;
const int MM = 3e5+5, mod = 1e9+7;
int N, M, K, lo, hi; vector<pi> adj[MM]; pi val[MM]; long long ans = 1; bool vis[MM], vis2[MM];
void dfs(int u){
    vis[u] = 1;
    for(pi e: adj[u]){
        int v = e.f, w = e.s;
        if(!vis[v]){val[v] = {-val[u].f, w-val[u].s}; dfs(v); }
    }
}
void dfs2(int u){
    vis2[u] = 1;
    if(val[u].f > 0) { lo = max(lo, 1-val[u].s); hi = min(hi, K-val[u].s); }
    else { lo = max(lo, val[u].s-K); hi = min(hi, val[u].s-1); }
    for(pi e: adj[u]){
        int v = e.f, w = e.s;  pi tmp = {-val[u].f, w - val[u].s};
        if(val[v] == tmp) continue;
        if(val[v].f == tmp.f || (val[v].s - tmp.s)%(tmp.f - val[v].f) != 0){
            printf("0\n"); exit(0);
        }
        int sol = (val[v].s - tmp.s)/(tmp.f - val[v].f);
        lo = max(lo, sol); hi = min(hi, sol);
    }
    for(pi e: adj[u])
        if(!vis2[e.f]) dfs2(e.f);
}
int main(){
    scanf("%d %d %d", &N, &M, &K);
    for(int i=1, u, v, w; i<=M; i++){
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back({v, w}); adj[v].push_back({u, w});
    }
    for(int i=1; i<=N; i++){
        if(!vis[i]){
            val[i]={1, 0}; dfs(i);
            lo = 1, hi = K;  dfs2(i);
            if(lo > hi) { printf("0\n"); exit(0); }
            ans = (ans * (hi - lo + 1)) % mod;
        }
    }
    printf("%lld\n", ans);
}
