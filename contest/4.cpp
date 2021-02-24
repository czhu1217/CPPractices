#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef pair<ll, ll> pi;
#define FOR(i, a, b) for (ll i=a; i<=(b); i++)
#define pb push_back
#define f first
#define s second
const ll MM = 2e5+5;
ll n, w, d, u, v, sub[MM], dis[MM], c;
ll ans=LLONG_MAX; vector<int> pos;
vector<ll> adj[MM], adj2[MM];
map<int, vector<int>> mp;
bool vis[MM];
int main(){
    cin >> n >> w >> d;
    FOR(i, 1, n) dis[i] = -1;
    FOR(i, 1, w){
        cin >> u >> v;
            adj[u].pb(v); 
            adj2[v].pb(u);
    }
    FOR(i, 1, n){
        cin >> sub[i];
    }
    queue<pi> q;
    dis[n] = 0;
    q.push({n, 0}); vis[n] = 1;
    while(!q.empty()){
        u = q.front().f, c = q.front().s;
        q.pop();
        dis[u] = c;
        for(auto e:adj2[u]){
            if(!vis[e]){
                vis[e] = 1;
                q.push({e, c+1});
            }
        }
    }
    // // FOR(i, 1, n) cout << dis[i] << " ";
    FOR(i, 1, n){
        if(dis[sub[i]]<0) continue;
        mp[i-1+dis[sub[i]]].pb(i);
    }
    ll temp, x, y;
    bool ok;
    FOR(j, 1, d){
        ok = 0;
        cin >> x >> y;
        temp = sub[x];
        sub[x] = sub[y];
        sub[y] = temp;
        
        mp[x-1+dis[sub[x]]].pb(x);
        mp[y-1+dis[sub[y]]].pb(y);
        for(int i=mp.size()-1;i>=0;i--){
            for(int j=0;j<mp[i].size();j++)
        }

        cout << ans << "\n";

    }
    return 0;
}