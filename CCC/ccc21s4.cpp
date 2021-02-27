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
ll ans=LLONG_MAX; map<ll, bool> pos;
vector<ll>  adj2[MM];
set<pi> se;

bool vis[MM];
int main(){
    cin >> n >> w >> d;
    FOR(i, 1, n) dis[i] = -1;
    FOR(i, 1, w){
        cin >> u >> v;
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
    FOR(i, 1, n){
        if(dis[sub[i]]>=0)
        se.insert({i-1+dis[sub[i]], sub[i]});
    }

    ll temp, x, y;
    FOR(i, 1, d){
        ans = LLONG_MAX;
        cin >> x >> y;
        se.erase({x-1+dis[sub[x]], sub[x]});
        se.erase({y-1+dis[sub[y]], sub[y]});
        temp = sub[x];
        sub[x] = sub[y];
        sub[y] = temp;
        if(dis[sub[x]]>=0) se.insert({x-1+dis[sub[x]], sub[x]});
        if(dis[sub[y]]>=0) se.insert({y-1+dis[sub[y]], sub[y]});
        ans = (*se.begin()).f;
        cout << ans << "\n";

    }
    return 0;
}