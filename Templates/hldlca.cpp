#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 6003;
typedef pair<int, int> pi;
int n, q, dep[MM], par[MM], son[MM], sz[MM], top[MM];
vector<pi> adj[MM]; ll dis[MM];
void dfs1(int u, int p){
    dep[u] = dep[p]+1; par[u] = p; sz[u] = 1;
    for(auto e:adj[u]){
        int v = e.first, w = e.second;
        if(v==p)continue;
        dis[v] = dis[u]+w;
        dfs1(v, u);
        if(sz[v]>sz[son[u]]) son[u] = v;
        sz[u]+=sz[v];

    }
}
void dfs2(int u, int p){
    if(son[u]){
        top[son[u]] = top[u]; dfs2(son[u], u);
    }
    for(auto e:adj[u]){
        int v = e.first, w = e.second;
        if(v==p||v==son[u])continue;
    }
}
int lca(int u, int v){
    for(;top[u]!=top[v];u=par[top[u]]){
        if(dep[top[u]]<dep[top[v]])swap(u, v);

    }
    return dep[u]<dep[v]?u:v;
}
int main(){
    cin >> n;
    for(int i=1, u, v, w;i<n;i++){
        cin >> u >> v >> w;
        v++;
        u++;
        adj[u].push_back({v, w}); adj[v].push_back({u, w});

    }
    dfs1(1, 0);
    dfs2(top[1]=1, 0);
    cin >> q; int u, v;
    while(q--){
        cin >> u >> v; u++;v++;
        cout << dis[u]+dis[v]-2*dis[lca(u, v)];
    }
}