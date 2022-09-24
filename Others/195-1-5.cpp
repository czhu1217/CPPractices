#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
 
#define FOR(i, a, b) for (int i=a; i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
const ll MM = 2e5+5;
int n;
int c[MM];
bool vis[MM], vis2[MM];
int id[MM];
// bool adj[MM][MM];
vector<int> adj[MM], adj2[MM];
int cnt[2];   
void dfs(int u, int i){
    id[u] = i;
    vis[u] = 1;
    for(auto e:adj[u]){
        if(vis[e]) continue;
        if(c[e]==c[u]){
            dfs(e, i);
        }
    }
}
void dfs2(int u){
    vis2[u] = 1;
    for(auto e:adj[u]){
        if(vis2[e]) continue;
        if(c[e]!=c[u]){
            adj2[id[e]].pb(id[u]);
            adj2[id[u]].pb(id[e]);

        }
        dfs2(e);
    }
}
pair<int, int> dfs3(int u){
    int node, dis;
    node = dis = 0;
    node = u;
    vis[u] = 1;
    for(auto e:adj2[u]){
        if(vis[e]) continue;
        pair<int, int> p = dfs3(e);
        if(p.second+1>dis){
            dis = p.second+1;
            node = p.first;
        }
    }
    return {node, dis};
}
int main(){
    cin >> n;
    FOR(i, 1, n){
        cin >> c[i];
    }
    int u, v;
    FOR(i, 1, n-1){
        cin >> u >> v;
        adj[u].pb(v); adj[v].pb(u);
    }
    int idx = 1;
    FOR(i, 1, n){
        if(!vis[i]){
            // cout << "visiitng " << i << "\n";
            dfs(i, idx++);
        }
    }
    dfs2(1);
    // FOR(j, 1, n) cout << id[j] << " ";
    // cout << "\n";
    // FOR(i, 1, n){
    //     for(auto e:adj2[i]) cout << e << " ";
    //     cout << "\n";
    // }
    memset(vis, 0, sizeof vis);
    pair<int, int> p1 = dfs3(1);
    memset(vis, 0, sizeof vis);
    pair<int, int> p2 = dfs3(p1.first);
    cout << (p2.second+1)/2 << "\n";
    

}