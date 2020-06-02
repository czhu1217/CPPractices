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
const int MM = 1e5+5, LOG=17;
int n, dep[MM], pa[LOG][MM], dif[MM];
unordered_map<ll, int> m;
vector<int> adj[MM], color[MM];
void add(int u, int v, int id){
    if(u<v)swap(u, v);
    ll hsh = (ll)u*MM+v;
    if(m.count(hsh)){
        adj[m[hsh]].pb(id); adj[id].pb(m[hsh]);
    }
        else m[hsh] = id;

}
void dfs(int u, int p, int d){
    dep[u] = d;
    pa[0][u] = p;
    for(auto e:adj[u]){
        if(e!=p) dfs(e, u, d+1);
    }
}
void build(){
    for(int i=1;i<LOG;i++){
        for(int j=1;j<=n;j++){
            pa[i][j] = pa[i-1][pa[i-1][j]];
        }
    }
}
int lca(int u, int v){
    if(dep[u]<dep[v]) swap(u, v);
    for(int i=LOG-1;i>=0;i--){
        if(dep[pa[i][u]]>=dep[v]) u = pa[i][u];

    }
    if(u==v)return u;
    for(int i=LOG-1;i>=0;i--){
        if(pa[i][v]!=pa[i][u]){ u = pa[i][u]; v = pa[i][v];}
    }
    return pa[0][u];
}
void dfs2(int u, int p){
    for(auto e:adj[u]){
        if(e!=p){
            dfs2(e, u);
            dif[u] += dif[e];
        }
    }

}
int main(){
    cin >> n;
    for(int i=1, a, b, c, d;i<=n-2;i++){
        cin >> a >> b >> c >> d;
        add(a, b, i); add(a, c, i); add(b, c, i);
        color[d].push_back(i);
    }
    dfs(1, 0, 0);
    build();
    for(int i=1;i<=n;i++){
        if(color[i].empty()) continue;
        for(int j=1;j<color[i].size();j++){
            int u = color[i][j-1], v = color[i][j], rt = lca(u, v);
            dif[u]++; dif[v]++; dif[rt] -= 2;
        }
    }
    dfs2(1, 0);
    int ans=0;
    for(int i=2;i<=n-2;i++){
        ans += (dif[i]==0);
    }
    cout << ans << '\n';

    return 0;
}