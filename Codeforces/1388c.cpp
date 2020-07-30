
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
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
const int MM = 1e5+5;
bool pos =1;
int a[100005], h[100005], par[100005]; ll s[100005];
vector<vector<int>> adj;

void dfs(int u, int p){
    par[u] = p;
    for(auto e:adj[u]){
        if(e!=p) dfs(e, u);
    }
}
void dfs2(int u, int p){
    s[u] = a[u];
    for(auto e:adj[u]){
        if(e!=p){
            dfs2(e, u);
            s[u] += s[e];
        }
    }
    if(s[u]<h[u]){
        pos = 0;

    }
    if((s[u]+h[u])%2||(s[u]+h[u])<0){ pos=0; }
    if((s[u]-h[u])<0||(s[u]-h[u])%2){ pos =0;   }


    
}
void dfs3(int u, int p){
    ll temp=0, loc = (s[u]+h[u])/2;
    for(auto e:adj[u]){
        if(e!=p){ 
            temp += (s[e]+h[e])/2;
            dfs3(e, u);
        }
    }
    if(temp>loc){
        pos=0;
    }
}
int n, m;
void solve(){
    pos = 1;
    adj.clear();cin >> n >> m;
    adj.resize(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++) cin >> h[i];
    for(int i=1, x, y;i<n;i++){
        cin >> x >> y;
        adj[x].pb(y); adj[y].pb(x);
    }
    dfs(1, 0);
    dfs2(1, 0);
    dfs3(1, 0);


    if(pos) cout << "YES\n";
    else cout << "NO\n";


}
int main(){
    int t; cin >> t;
    while(t--)solve();
    return 0;
}