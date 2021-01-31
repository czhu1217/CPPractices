//very very weird dijkstra
//custom priority queue
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
const ll MM = 2e5+5;
ll n, m, t[MM], a, b, w, lvl[MM], mini[MM];
vector<pi> adj[MM];
bool vis[MM];
struct ed{
    ll u;ll co; ll mi, lv;
    bool  operator<(const ed &e){
        return co<e.co;
    }
};
struct com {
    bool operator()(ed const& p1, ed const& p2)
    {
        return p1.co > p2.co;
    }
};
    ll u, mi, v, lv; ll co;

priority_queue<pi, vector<ed>, com> q;
int main(){
    memset(mini, 0x3f, sizeof mini);
    cin >> n >> m;
    FOR(i, 1, n) cin >> t[i];
    FOR(i, 1, m){
        cin >> a >> b >> w;
        adj[a].pb({b, w}); adj[b].pb({a, w});
    }
    q.push({1, 0, t[1], 1});
    while(!q.empty()){
        u = q.top().u; mi = q.top().mi, co = q.top().co; lv = q.top().lv;
        q.pop();
        lvl[u] = max(lvl[u], lv);
        mini[u] = min(mini[u], mi);
        if(u==n){
            cout << co << "\n";
            return 0;
        }
        for(auto e:adj[u]){
            v = e.f, w = e.s;
            if(max(lv, w)>lvl[e.f]||mi<mini[e.f]){
                q.push({v, co+mi*max(1LL*0, w-lv), min(mi, t[v]), max(lv, w)});
            }
        }
    }
    cout << -1 << "\n";

    return 0;
}