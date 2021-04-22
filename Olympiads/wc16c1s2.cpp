#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef pair<int, int> pi;
#define FOR(i, a, b) for (int i=a; i<=(b); i++)
#define pb push_back
#define f first
#define s second
const int MM = 2e5+5;
int n, k, in[MM];
vector<pi> adj[MM];
ll ans;bool vis[MM], done[MM];
int main(){
    vis[1] = 1;
    cin >> n >> k;
    int u, v, w;
    FOR(i, 1, n-1){
        cin >> u >> v >> w;
        adj[u].pb({v, w}); adj[v].pb({u, w});
        in[u]++;in[v]++;
        ans += w;
    }
    FOR(i, 1, k){
        cin >> u; vis[u] = 1;
    }
    vector<int> ve;
    FOR(i, 1, n){
        if(in[i]==1&&!vis[i]){
            ve.pb(i);
        } 
    }
    while(!ve.empty()){
        u = ve.back();ve.pop_back();
        in[u]--;
        done[u]=1;
        for(auto e:adj[u]){
            in[e.f]--;
            if(!done[e.f]) ans -= e.s;
            if(in[e.f]==1&&!vis[e.f]){
                ve.pb(e.f);
            } 
        }
    }
    cout << ans << "\n";


    return 0;
}