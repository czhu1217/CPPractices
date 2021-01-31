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
const int MM = 2e5+5;
int n,a ,b, dis[MM], par[MM], mx; bool vis[MM];
vector<int> adj[MM];
vector<int> di[MM];
vector<pi> ans;
void dfs(int u){
    vector<int> v;
    bool pos = 0;
    for(auto e:adj[u]){
        if(e!=par[u]){
        par[e] = u;
        dfs(e);
        }
    }
    for(auto e:adj[u]){
        if(e!=par[u]&&!vis[e]){
           v.pb(e);
        }
    }
    for(int i=1;i<v.size();i+=2){
        ans.pb({v[i], v[i-1]});
        vis[v[i]] = 1; vis[v[i-1]] = 1;
    }
    if(u!=1){
    for(auto e:adj[u]){
        if(!vis[e]&&e!=par[u]&&!vis[u]){
            vis[u] = 1; vis[e] = 1;
            ans.pb({e, par[u]});
            break;
        }
    }
    }
    
}
int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    FOR(i, 1, n-1){
        cin >> a >> b;
        adj[a].pb(b);adj[b].pb(a);
    }
    dfs(1);
    cout << ans.size() << "\n";
    for(auto e:ans){
        cout << e.f << " " << e.s << "\n";
    }
    return 0;
}