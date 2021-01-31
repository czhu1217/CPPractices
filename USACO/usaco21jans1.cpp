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
int n, k, a[MM], x, y, t, ans[MM];
vector<int> adj[MM]; 
bool vis[MM];

int main(){
    // cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> k;
    FOR(i, 1, n) a[i] = i;
    FOR(i, 1, k){
        cin >> x >> y;
        t = a[x];
        a[x] = a[y];
        a[y] = t;
        adj[a[x]].pb(x); adj[a[y]].pb(y);
    }
    FOR(i, 1, n){
        if(vis[i]) continue;
        if(adj[i].size()==0){
            ans[i] = 1;
            continue;
        }
        vector<int> v;
        v.pb(i);
        set<int> se;
        for(int j=0;j<adj[i].size();j++){
            se.insert(adj[i][j]);
        }
        t = adj[i].back();
        while(t!=i){
            v.pb(t);
            for(int j=0;j<adj[t].size();j++){
                se.insert(adj[t][j]);
            }
            t = adj[t].back();
        }
        for(auto e:v){
            ans[e] = se.size();
            vis[e] = 1;
        }
    }
    FOR(i, 1, n){
        cout << ans[i] << "\n";
    } 
    return 0;
}