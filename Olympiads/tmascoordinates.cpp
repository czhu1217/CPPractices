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
int n, q, ans1, ans2, dis1[MM], dis2[MM],dis3[MM], mx, mx2;
vector<pi> adj[MM];
void dfs(int u, int p){
    if(dis1[u]>mx){
        mx = dis1[u]; 
        ans1 = u;
    }
    for(auto e:adj[u]){
        if(e.f!=p){
            dis1[e.f] = dis1[u]+e.s;
            dfs(e.f, u);
        }
    }
}
void dfs2(int u, int p){
    if(dis2[u]>mx2){
        ans2 = u; mx2 = dis2[u];
    }
    for(auto e:adj[u]){
        if(e.f!=p){
            dis2[e.f] = dis2[u]+e.s;
            dfs2(e.f, u);
        }
    }
}
void dfs3(int u, int p){
    for(auto e:adj[u]){
        if(e.f!=p){
            dis3[e.f] = dis3[u]+e.s;
            dfs3(e.f, u);
        }
    }
}
int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> q;
    int u, v, w;
    FOR(i, 1, n-1){
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    dfs(1, 1);
    dfs2(ans1, ans1);
    dfs3(ans2, ans2);
    // cout << ans1 << " " << ans2 << "\n";
    int x;
    while(q--){
        cin >> x;
        cout << max(dis2[x], dis3[x]) << "\n";
    }
    return 0;
}