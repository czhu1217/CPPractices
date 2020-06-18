
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
const ll MM = 1e4+2;
vector<pi> adj[MM];
ll vis[MM], brt[MM], dk[MM];
struct ev{
    ll u, lo, hi, dis;
};
ll n, m;
queue<ev> qu;
int main(){
    memset(vis, 0x3f, sizeof vis);
    memset(dk, 0x3f, sizeof dk);
    memset(brt, 0, sizeof brt);
    cin >> n >> m;
    for(ll i=1,u, v, z;i<=m;i++){
        scanf("%lld%lld%lld", &u, &v, &z);
        adj[u].pb({v, z}); adj[v].pb({u, z});
    }
    qu.push({1, 0, 0, 0});
    vis[1]=0;
    brt[1]=0; dk[1]=0;

    while(!qu.empty()){

       ll u = qu.front().u, lo = qu.front().lo, hi = qu.front().hi, d = qu.front().dis;
        qu.pop();
        for(auto e:adj[u]){
            if(d+1<=vis[e.f]){
                brt[e.f] = max(brt[e.f], e.s+hi);
                dk[e.f] = min(dk[e.f], e.s+lo);
                qu.push({e.f, e.s+lo, e.s+hi, d+1});
                vis[e.f] = d+1;
            }
        }
    }
    ll q; cin >> q;
    for(ll i=1;i<=q;i++){
        ll e; cin >> e;
        string temp; cin >> temp;
        if(temp=="White"){
            cout << vis[e] << " " <<  brt[e] << "\n";
        }
        else cout << vis[e] << " " << dk[e] << "\n";
    }
    return 0;
}