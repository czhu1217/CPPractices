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
 
#define INF 0x3f3f3f3f
#define LL_INF 0x3f3f3f3f3f3f3f3f 
#define sz(x) (int)(x).size()
#define ms(x, y) memset(x, y, sizeof(x))
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
int c, r, d;
const int MM = 1e4+5;
vector<pi> adj[MM];
int dis[MM], x, y, w;
vector<int> v; bool vis[MM];
priority_queue<pi> q;
int ans = INF;
int main(){
    cin >> c >> r >> d;
    FOR(i, 1, r){
        cin >> x >> y >> w;
        adj[x].pb({y, w});
        adj[y].pb({x, w});
    }
    FOR(i, 1, d){
        cin >> x; v.pb(x);
    }
    q.push({INF, 1});
    while(!q.empty()){
        int co, v, u, w;
        u = q.top().s, co = q.top().f;
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        dis[u] = co;
        for(auto e:adj[u]){
            v = e.f, w = e.s;
            if(!vis[v]){
                q.push({min(w, co), v});
            }
        }

    }
    for(auto e:v){
        ans = min(ans, dis[e]);
    }
    cout << ans << "\n";
    return 0;
}