#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef pair<ll, ll> pi;
#define FOR(i, a, b) for (ll i=a; i<=(b); i++)
#define pb push_back
#define f first
#define s second
const ll MM = 2e5+5;
ll n, m, a, b; bool even[MM];
vector<pi> adj[MM]; bool vis[MM], onpath[MM];
vector<ll> v;
void dfs(ll u, ll p){
    if(even[u]){
        even[u] = 0;
        vis[p] = 1;
        return;
    }
    onpath[u] = 1;
    for(auto e:adj[u]){
        if(onpath[e.f]) continue;
        if(vis[e.s]) continue;
        dfs(e.f, e.s);
        if(vis[e.s]){ //the path beyond this point worked out
            vis[p] = 1;
            return;
        }

    }
    onpath[u] = 0;
}
ll cnt;
int main(){
    cin >> n >> m;
    FOR(i, 1, m){
        cin >> a >> b;
        adj[a].pb({b, i}); adj[b].pb({a, i});
    }
    FOR(i, 1, n){
        if(adj[i].size()%2==0) even[i] = 1;
    }
    FOR(i, 1, n){
        if(even[i]){
            onpath[i] = 1;
            // cout << "ok " <<  i << "\n";
            for(auto e:adj[i]){
                if(!vis[e.s]){
                    dfs(e.f, e.s);
                    if(vis[e.s]){
                        // cout << "works\n";
                        even[i] = 0;
                        onpath[i] = 0;
                        break;
                    }
                }
            }
            onpath[i] = 0;
        }
    }
    FOR(i, 1, n) if(!even[i]) cnt++;
    FOR(i, 1, m){
        if(vis[i]){
            v.pb(i);
        }
    }
    cout << cnt << "\n";
    cout << v.size() << "\n";
    for(auto e:v){
        cout << e << " ";
    }
    return 0;
}