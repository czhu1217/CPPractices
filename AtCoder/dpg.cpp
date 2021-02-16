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
const int MM = 1e5+5;
int n, m, x, y, ind[MM], dis[MM];
vector<int> adj[MM];
void dfs(int u){
    if(adj[u].empty()||dis[u]) return;
    // cout << u << "\n";
    for(auto e:adj[u]){
            dfs(e);
            dis[u] = max(dis[u], dis[e]+1);
    }
}
int main(){
    // cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> m;
    FOR(i, 1, m){
        cin >> x >> y;
        adj[x].pb(y);
        ind[y]++;
    }
    FOR(i, 1, n){
        dfs(i);
    }
    int ans=0;
    FOR(i, 1, n) ans = max(ans, dis[i]);
    cout << ans << "\n";
    return 0;
}