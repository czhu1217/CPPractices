#include <bits/stdc++.h>
using namespace std; 
 
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
typedef long long ll;
const ll MM = 2e5+5;
ll n, a[MM];vector<ll> adj[MM], adj2[MM]; ll ans; ll in[MM], out[MM];
ll ans1, ans2; ll mx = 0;
bool vis[MM], vis2[MM]; ll cnt; ll b[MM], tot[MM];
vector<ll> v;
void dfs(ll u){

    tot[u] = a[u];

    vis[u] = 1;
    for(auto e:adj[u]){
        if(!vis[e]) dfs(e);
        tot[u] += tot[e];
    } 
    b[u] = a[u]*(tot[u]-1);
}
void dfs2(ll u){

    in[u] = a[u];

    vis2[u] = 1;
    for(auto e:adj2[u]){
        if(!vis2[e]) dfs2(e);
        in[u] += in[e];
    } 
}
int main(){
    memset(vis, 0, sizeof vis);
    memset(vis2, 0, sizeof vis2);
    cin >> n;
    FOR(i, 1, n) cin >> a[i]; ll ai, bi;
    FOR(i, 1, n-1){
        cin >> ai >> bi;
        adj[ai].pb(bi);
        adj2[bi].pb(ai);
    }
    for(ll i=1;i<=n;i++){
        if(vis[i])continue;
        cnt = 0;
        dfs(i);
    }
    for(ll i=1;i<=n;i++){
        if(vis2[i])continue;
        cnt = 0;
        dfs2(i);
    }
    FOR(i, 1, n) ans += b[i]; ll best = 0;
    for(ll i=1;i<=n;i++){
        for(auto e:adj[i]){
            // cout << i << " " << e << " " << (in[e]-in[i])*(tot[i]-tot[e]) << "\n";
            best = max(best, (in[e]-in[i])*(tot[i]-tot[e]));
        }
    }
    // for(ll i=1;i<=n;i++) cout << in[i] << " " << tot[i] << "\n";
    // cout << ans << "\n";
    cout << ans+best << "\n";



    return 0;
}