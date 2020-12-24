//dijkstra
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
int n, m, ans=-1;
vector<pi> adj[MM];
priority_queue<pair<pi,int>, vector<pair<pi, int>>, greater<pair<pi, int>>> q;
bool vis[MM];int par[MM], cnt;
bool comp(pi a, pi b){
    return a.s < b.s;
}
int main(){
    memset(vis, 0, sizeof vis);
    cin >> n >> m;int u, v, w;
    FOR(i, 1, m){
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    q.push({{0, 0}, 1}); vis[1] = 1;
    while(!q.empty()){
        pair<pi, int> p = q.top();  q.pop();
        u = p.s, w = p.f.f;
        vis[u] = 1;
        if(u==n){
            cout << w << " " <<  p.f.s << "\n";
            return 0;
        }
        for(auto e:adj[u]){
            if(!vis[e.f]){
                q.push({{w+e.s, p.f.s+1}, e.f});
            }
        }
    }
   cout << -1 << "\n";
    return 0;
}