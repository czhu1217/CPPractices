
#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <string>
#include <climits>
#define f first
#define s second
using namespace std; 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<ll> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
 
#define FOR(i, a, b) for (ll i=a; i<=(b); i++)
#define F0R(i, a) for (ll i=0; i<(a); i++)
#define FORd(i,a,b) for (ll i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (ll i = (a)-1; i >= 0; i--)
 
#define sz(x) (ll)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
const int MM = 2e5+5;
ll n, sz[MM], dp[MM], pa[MM], a[MM], len[MM]; vector<int> adj[MM];
void dfs1(int u, int p){
    sz[u] = 1; dp[u] = 0;
    for(auto v:adj[u]){
        if(v!=p){
            dfs1(v, u);
            sz[u] += sz[v]; 
            dp[u] += dp[v] + sz[v];
        }
    }
}
void dfs2(int u, int p){
    len[u] = dp[u]*(n-sz[u]+1)+pa[u]*sz[u];
    for(int v:adj[u]){
        if(v==p)continue;
        len[u] += (sz[u]-sz[v]-1)*(dp[v]+sz[v]);
        pa[v] = dp[u]-dp[v]-sz[v]+pa[u]+n-sz[v];
        dfs2(v, u);
    }
}
int main(){
    cin >> n;
    for(int i=1;i<=n;i++)cin >> a[i];
    for(int i=1, u, v;i<n;i++){
        cin >> u >> v;
        adj[u].pb(v); adj[v].pb(u);
    }
    dfs1(1, 0); dfs2(1, 0);
    ll ans=0;
    for(int i=1;i<=n;i++){
        ans += a[i]*len[i];
    }
    cout << ans << "\n";
    return 0;


}