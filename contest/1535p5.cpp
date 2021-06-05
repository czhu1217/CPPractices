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
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
const int MM = 3e5+5, LOG = 19;
int a0, c0, q, op, p, a, c, v, w, par[LOG][MM];
vi adj[MM];
pi ver[MM];

void build(){
    for(ll i=1;i<LOG;i++){
            ll p = par[i-1][j];
            par[i][j] = par[i-1][p];
    }
}


int main(){
    cin >> q >> a0 >> c0;
    FOR(i, 1, q){
        cin >> op;
        if(op==1){
            cin >> p >> a >> c;
            par[0][i] = p;
            adj[p].pb(i);
            adj[i].pb(p);
            ver[i].f = a; ver[i].s = c;
            for(ll j=1;j<LOG;j++){
                ll pi = par[j-1][i];
                par[j][i] = par[j-1][pi];
            }


        }else{
            cin >> v >> w;


        }
    }   
 

    return 0;
}