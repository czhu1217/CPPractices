#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef pair<int, int> pi;
#define FOR(i, a, b) for (int i=a; i<=(b); i++)
#define pb push_back
#define f first
#define s second
const int MM = 2e5+5;
vector<pi> adj[MM], adj2[MM], tmp[MM];
int cost[MM];
int n, co, a, b, c, d;
bool vis[MM]; int idx[MM], par[MM], rnk[MM];
pair<pi, pi> pp[MM];
vector<pair<int, pi>> ed;
void dfs(int u, int id){
    vis[u] = 1;
    idx[u] = id;
    for(auto v:adj[u]){
        if(!vis[v.f]){
            dfs(v.f, id);
        }
    }
}
int find(int n)
{
    if (par[n] != n)
    {
        return find(par[n]);
    }
    return n;
}
bool merge(int a, int b)
{
    int x = find(a);
    int y = find(b);
    if (x == y)
        return false;
    if (rnk[x] > rnk[y])
    {
        par[y] = x;
        return true;
    }
    par[x] = y;
    if (rnk[y] == rnk[x])
    {
        rnk[y]++;
    }

    return true;
}

int main(){
    cin >> n;
    FOR(i, 1, n){
        cin >> co >> a >> b >> c >> d;
        cost[i] = co;
        adj[a].pb({b, i});
        adj[b].pb({a, i});
        adj[c].pb({d, i});
        adj[d].pb({c, i});
        pp[i] = {{a, b}, {c, d}};
        

    }
    int cnt = 0;
    FOR(i, 1, 2*n){
        if(!vis[i]){
            dfs(i, ++cnt);
        }
    }
    int u, v;
    ll cos =0;
    FOR(i, 1, n){
        u = idx[pp[i].f.f];
        v = idx[pp[i].s.f];
        adj[u].pb({v, cost[i]});
        adj[v].pb({u, cost[i]});
        ed.pb({cost[i], { u, v}});
    }
    sort(ed.begin(), ed.end());
    
    for (int i = 1; i <= cnt; i++)
    {
        par[i] = i;
    }
    int count = 0;

    for (int i = 0; i < ed.size(); i++)
    {
        if (count == n - 1)
        {
            break;
        }
        if (merge(ed[i].s.f, ed[i].s.s))
        {
            cos += ed[i].f;
            count++;

        }
    }
    cout << cos << "\n";

    return 0;
}