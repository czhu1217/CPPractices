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
const ll MM = 1e6+5;
ll h, a, b, c, dis[MM], ans;
vector<pi> adj[MM];
priority_queue<pi, vector<pi>, greater<pi>> q;
int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    memset(dis, 0x3f, sizeof dis);
    cin >> h >>a >> b >> c;
    if(a==1||b==1||c==1){
        cout << h << endl;
        return 0;
    }
    for(ll r = 0;r<a;r++){
        adj[r].pb({b, (r+b)%a});
        adj[r].pb({c, (r+c)%a});
    }
    dis[1] = 1;
    q.push({1, dis[1]});
    while(!q.empty()){
        ll d = q.top().f, u = q.top().s;
        q.pop();
        if(d>dis[u]) continue;
        for(auto e:adj[u]){
            if(e.f+d<dis[e.s]){
                dis[e.s] = e.f+d;
                q.push({e.f+d, e.s});
            } 
        }
    }
    for(ll r=0;r<a;r++){
        if(dis[r]<=h){
            ans += (h-dis[r])/a+1;
        }
    }
    cout << ans << endl;
    return 0;
}