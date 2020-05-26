//lca distance query
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <queue>
#include <fstream>
#include <iostream>
#define s second
#define f first
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
const ll MM = 1e5+5, LOG=17;
vector<pi> adj[MM];
ll dep[MM], anc[LOG][MM], n, d, dis[MM];
ll lca(ll u, ll v){
    if(dep[u]<dep[v])swap(u, v);
    for(ll i=LOG-1;i>=0;i--){
        if(dep[anc[i][u]]>=dep[v]) u = anc[i][u];
    }
    if(u==v)return u;
    for(ll i=LOG-1;i>=0;i--){
        if(anc[i][u]!=anc[i][v]){
            u = anc[i][u]; v = anc[i][v];
        }
    }
    return anc[0][u];
}
void build(){
    for(ll i=1;i<LOG;i++){
        for(ll j=1;j<=n;j++){
            ll p = anc[i-1][j];
            anc[i][j] = anc[i-1][p];
        }
    }

}
void dfs(ll u, ll p, ll w){
    dep[u] = dep[p]+1;
    anc[0][u] = p;
    dis[u] = dis[p]+w;
    for(auto e:adj[u])
        if(e.f!=p)
            dfs(e.f,u ,e.s);

}
ll dist(ll u, ll v){

    ll lc = lca(u, v);
    return dis[u]+dis[v]-2*dis[lc];
}
int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> d;
    for(ll i=1, u, v, w;i<n;i++){
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dis[0]=0;
    dfs(1, 1, 0);
    build();
    ll pre1=1, pre2=1, val1=0, val2=0, cur1, cur2;
    for(ll i=1, x, y; i<=d; i++){
        cin >> x >> y;
        cur2 = min(val1+dist(x, pre1), val2+dist(x, pre2))+dist(x, y);
        cur1 = min(val1+dist(pre1, y), val2+dist(pre2, y))+dist(x, y);
        pre1=x; pre2=y; val1 = cur1; val2 = cur2;
    }
    cout << min(val1, val2) << "\n";
    return 0;
}