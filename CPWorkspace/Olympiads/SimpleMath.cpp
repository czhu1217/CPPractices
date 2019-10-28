#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pi;
const int MM = 3e5 + 5, mod = 1e9+7;
int n, m, k, lo, hi;
bool vis[MM], vis2[MM];
vector<pi> adj[MM];
pi val[MM];
long long ans;
void dfs(int u){
    vis[u] = 1;
    for(pi e:adj[u]){
        int v = e.first, w=e.second;
        if(!vis[v]){
            val[v] = {-val[u].first, w-val[u].second};
            dfs(v);
        }
    }
}
void dfs2(int u){
    vis2[u] = 1;
    if(val[u].first>0){
        lo = max(lo, 1-val[u].second);
        hi = min(hi, k-val[u].second);

    }
    else{
        lo = max(lo, val[u].second-k);
        hi=min(hi, val[u].second-1);
    }
    for(pi e:adj[u]){
        int v = e.first, w=e.second;
        pi tmp = {-val[u].first, w-val[u].second};
        if(val[v]==tmp){
            continue;
        }
        if(val[v].first==tmp.first||(val[v].second-tmp.second)%(tmp.first-val[v].first)!=0){
            printf("0\n");
            exit(0);
        }
        int sol = (val[v].second-tmp.second)/(tmp.first-val[v].first);
        lo = max(lo, sol);
        hi = min(hi, sol);

    }
    for(pi e:adj[u]){
        if(!vis2[e.second]) dfs2(e.second);
    }
}
int main(){
    scanf("%d %d %d", &n, &m, &k);
    for(int i=1, u, v, w;i<=m;i++){
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
     }
     for(int i=1;i<=n;i++){
         if(!vis[i]){
             val[i] = {1, 0};
             dfs(i); 
             lo = 1;
             hi = k;
             dfs2(i);
             if(lo>hi){
                 printf("0\n");
                 exit(0);
             }
             ans = (ans*(hi-lo+1))%mod;

        }
     }
     printf("%lld\n", ans);
     return 0;

}
