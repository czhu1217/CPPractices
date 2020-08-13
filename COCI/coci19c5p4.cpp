//lca an difference array on a tree
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
const ll MM = 2e5+5, LOG=19;
ll n, par[LOG][MM], dep[MM], c1[MM], c2[MM]; ll dp[MM], dif[MM], tot[MM];
struct ed{
    ll v, c1, c2, id;
};
vector<ed> adj[MM];
ll lca(ll u, ll v){
    if(dep[u]<dep[v])swap(u, v);
    for(ll i=LOG-1;i>=0;i--){
        if(dep[par[i][u]]>=dep[v]) u = par[i][u];
    }
    if(u==v)return u;
    for(ll i=LOG-1;i>=0;i--){
        if(par[i][u]!=par[i][v]){
            u = par[i][u];
            v = par[i][v];
        }
    }
    return par[0][u];
}
void dfs(ll cur, ll pa){
    if(cur==1)dep[1] = 0;
    else dep[cur] = dep[pa]+1;
    par[0][cur] = pa;
    for(auto e:adj[cur]){
        if(e.v!=pa) dfs(e.v, cur);
    }
}
void build(){
    for(ll i=1;i<LOG;i++){
        for(ll j=1;j<=n;j++){
            ll p = par[i-1][j];
            par[i][j] = par[i-1][p];
        }
    }
}

void calc(ll cur, ll par, ll id){
    ll &res=dp[cur];
    res = 0;
    for(auto e:adj[cur]){
        if(e.v != par){
            calc(e.v, cur, e.id);
            res += dp[e.v];
        }
    }
    res += dif[cur];
    if(id>0) tot[id] = res;
}

int main(){
    cin >> n;
    FOR(i, 1, n-1){
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        adj[a].pb({b, c, d, i});
        adj[b].pb({a, c, d, i});
        c1[i] = c; c2[i] = d;
    }
    
    dfs(1, -1);
    build();
    // for(ll i=1;i<n;i++){
    //     cout << lca(i, i+1) << "\n";
    // }
    for(ll i=1;i<n;i++){
        ll lc = lca(i, i+1);
        dif[i]++; dif[i+1]++;
        dif[lc]-=2;

    }
    calc(1, -1, -1);
    ll ans=0;
    for(ll i=1;i<n;i++){
        ans += min((ll)c1[i]*tot[i], (ll)c2[i]);
    }
    cout << ans << "\n";

    return 0;

    
}