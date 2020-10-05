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
int n; bool vis[1002];
vector<int> adj[1002];
vector<int> v;
void dfs(int u){
    v.pb(u);
    vis[u] = 1;
    for(auto e:adj[u]){
        if(!vis[e]){
            dfs(e);
        }
    }
}
int main(){
    memset(vis, 0, sizeof vis);
    cin >> n; bool bo;
    FOR(i, 1, n){
        FOR(j, 1, n){
            cin >> bo;
            if(bo)adj[i].pb(j);
        }
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){ dfs(i);
        sort(v.begin(), v.end());
        for(auto e:v) cout << e << " ";
        v.clear();
        cout << "\n";
        }
    }
    return 0;
}