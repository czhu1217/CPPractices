//dij
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
const int MM = 5005, MN=1005;
int n, m, dis[MM];
vector<pi> adj[MM];
bool vis[MM];
priority_queue<pi, vector<pi>, greater<pi>> q;
int main(){
    cin >> n >> m;
    FOR(i,1,n) dis[i] = -1;
    int u, v, w;
    FOR(i, 1, m){
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    q.push({0, 1});
    while(!q.empty()){
        int u = q.top().s, w = q.top().f;
        if(vis[u]){
            q.pop();
            continue;
        }
        dis[u] = w;
        vis[u] = 1;
        q.pop();
        for(auto e:adj[u]){
            if(!vis[e.f]){
                q.push({e.s+w, e.f});
            }
        }
    }
    FOR(i, 1, n) cout << dis[i] << "\n";
    return 0;
}