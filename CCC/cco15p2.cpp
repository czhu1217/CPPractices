#include <bits/stdc++.h>
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
const ll MM = 20, M = (1<<19);
ll n, m, dp[MM][M];
vpi adj[MM]; 
bool dfs(ll u, ll msk){
    if(dp[u][msk]>0) return 1;
    else if(dp[u][msk]==-1) return 0;
    if(u==n-1) return 1;
    bool pos = 0;
    ll mx = 0;
    for(auto e:adj[u]){
        if(!(msk&(1<<(e.f)))){
            if(dfs(e.f, msk|(1<<(e.f)))){
                pos = 1;
                mx = max(mx, dp[e.f][msk|(1<<(e.f))]+e.s);
            }
        }
    }
    if(pos)
    dp[u][msk] = mx;
    else dp[u][msk] = -1;
    return pos;

}
int main(){
    cin >> n >> m;
    ll u, v, w;
    FOR(i, 1, m){
        cin >> u >> v >> w;
        adj[u].pb({v, w});
    }
    dfs(0, 1);
    cout << dp[0][1] << "\n";

    return 0;
}