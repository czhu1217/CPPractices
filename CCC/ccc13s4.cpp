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
const int MM = 1e6+4;
int n, m, p, q;
vector<int> adj[MM];
bool vis[MM];
void dfs(int u, int p){
    vis[u] = 1;
    for(auto e: adj[u]){
        if(e!=p&&!vis[e]) dfs(e, u);
    }
}
int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> m;
    int x, y;
    FOR(i, 1, m){
        cin >> x >> y;
        adj[x].pb(y);
    }
    cin >> p >> q;
    dfs(p, p);
    if(vis[q]){
        cout << "yes\n";
        return 0;
    }
    memset(vis, 0, sizeof vis);
    dfs(q, q);
    if(vis[p]){
        cout << "no\n";
        return 0;
    }
    cout << "unknown\n";
    return 0;
}