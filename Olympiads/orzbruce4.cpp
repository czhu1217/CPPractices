#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef pair<int, int> pi;
#define FOR(i, a, b) for (int i=a; i<=(b); i++)
#define pb push_back
#define f first
#define s second
const int MM = 2e5+5, mod=1e9+7;
int n, m, k, u, v;
vector<int> adj[MM];
int dis[MM], dis2[MM]; bool vis[MM];
void bfs(int u){
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        u = q.front();
        q.pop();
        for(auto e:adj[u]){
            if(!vis[e]){
                q.push(e); vis[e]=1;
                dis[e] = dis[u]+1;
            }
        }
    }
}
void bfs2(int u){
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        u = q.front();
        q.pop();
        for(auto e:adj[u]){
            if(!vis[e]){
                q.push(e); vis[e]=1;
                dis2[e] = dis2[u]+1;
            }
        }
    }
}
ll quick_pow(ll x, int exp){
    if(exp==0)return 1;
    ll t = quick_pow(x, exp/2);
    t = t*t%mod;
    return (exp&1)?t*x%mod:t;
}
int main(){
    memset(dis, 0x3f, sizeof dis);
    memset(dis2, 0x3f, sizeof dis2);
    cin >> n >> m >> k;
    dis[1] = 0; dis2[n] = 0;

    FOR(i, 1, m){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    bfs(1); 
    memset(vis, 0, sizeof vis);
    bfs2(n);
    ll cnt = 2;
    FOR(i, 2, n-1){
        dis[i] = max(dis[i], dis2[i]);
        if(dis[i]<=k) cnt++;
    }
    cout << quick_pow(2, cnt-2) << "\n";
    return 0;
}