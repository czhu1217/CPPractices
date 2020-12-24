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
int n, cost[MM] ,sz;
vector<int> adj[MM];
queue<int> q; bool vis[MM];
int main(){
    scanf("%d", &n); int u, v;
    FOR(i, 1, n-1){
        scanf("%d %d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    q.push(1); vis[1] = 1;
    while(!q.empty()){
        u = q.front();q.pop();
        sz = adj[u].size()+(u==1);
        int t = ceil(log2(sz*1.0));
        cost[u] += t;
        for(auto e:adj[u]){
            if(vis[e]) continue;
            cost[e]++;
            vis[e] = 1;
            q.push(e);
        }

    }
    int ans = 0;
    FOR(i, 1, n) ans += cost[i];
    cout << ans << "\n";

    return 0;
}