
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
const int MN = 1e5+5, MM = 3e5+5;
int n, m, x,  h[MN];
ll cost[MN], ex[MN]; bool vis[MN];
vpi adj[MN];
priority_queue<pair<int, pi>> q;
// struct ev{
//     int u, int 
// }
void solve(){
    memset(ex, 0, sizeof ex);
    memset(cost, 0x3f, sizeof cost);
    cin >> n >> m >> x;
    for(int i=1;i<=n;i++) scanf("%d", &h[i]);
    for(int i=1, a, b, t;i<=m;i++){
        scanf("%d%d%d", &a, &b, &t);
        adj[a].pb({b, t});
        adj[b].pb({a, t});
    }
    ll ans = LLONG_MAX; ll curn;
    q.push({0, {1, x}});
    cost[1]=0;
    while(!q.empty()){
        pair<int, pi> temp = q.top(); q.pop();
        int u = temp.s.f, cur = temp.s.s;
        for(auto e:adj[u]){
            int w = max(0, e.s-cur); // how long you have to climb for
            if(cost[u]+w+e.s<cost[e.f]&&w<h[u]-cur+ex[u]&&cur-e.s<=h[e.f]){
                if(e.f==n) curn = max(0, cur-e.s);
                cost[e.f] = cost[u]+w+e.s;
                ex[e.f] = max((ll)0 , ex[u]+h[u]-(cur+w));
                q.push({cost[e.f], {e.f, max(0, cur-e.s)}});

            }
        }
    }
    if(cost[n]==4557430888798830399) cout << -1 << "\n";
    else cout << cost[n]+h[n]-curn << "\n";

    
}
int main(){
    solve();
    return 0;
}