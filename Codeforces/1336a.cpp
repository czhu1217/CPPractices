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

const int MM = 2e5+2;
vector<int> adj[MM]; ll dep[MM], sz[MM];
ll dfs(int u, int p, int d){
    dep[u] = d;
    ll size = 1;
    for(auto e:adj[u]){
        if(e!=p) size+=dfs(e, u, d+1);
    }
    sz[u] = size;
    return size;
}
void solve(){
    for(auto e:adj)e.clear();
    int n, k; cin >> n >> k;
    for(int i=1, u, v;i<n;i++){
        cin >> u >> v;
        adj[u].pb(v);adj[v].pb(u);
    }

    dfs(1, 0, 0);
    int val[MM];
    for(int i=1;i<=n;i++){
        val[i] = sz[i] - dep[i] - 1;
    }
    sort(val+1, val+n+1);
    reverse(val+1, val+n+1);
    ll ans=0;
    for(int i=1;i<=n-k;i++){
        ans += val[i];
    }

    cout << ans << "\n";
}
int main(){
    solve();
    return 0;
}