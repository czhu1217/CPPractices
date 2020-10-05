//Cycle detection
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
const int MM  = 1002;
vector<int> adj[MM];
int n; bool vis[MM], onstk[MM]; bool cyc = 0;
bool cyclic(int u){
    if(!vis[u]){
        onstk[u] = 1; vis[u] = 1;
        for(auto e:adj[u]){
            if(!vis[e]&&cyclic(e)) return 1;
            else if(onstk[e])return 1;
        }
    }
    onstk[u] = 0;
    return 0;
}
int main(){
    cin >> n; bool x;
    FOR(i, 1, n){
        FOR(j, 1, n){
            cin >> x;
            if(x){
                adj[i].pb(j);
            }
        }
    }
    FOR(i, 1, n){
        if(!vis[i]){
            if(cyclic(i)){
                cyc = 1; break;
            }
        }
    }
    if(cyc)cout << "NO\n";
    else cout << "YES\n";
   return 0;
}