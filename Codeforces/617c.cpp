
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
 
 
const ll MOD = 1000000007;
const char nl = '\n';
const ll MX = 100001; //check the limits, dummy
int main() {
	// ios_base::sync_with_stdio(0); cin.tie(0);    
	
    ll n; cin >> n;
    ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    pl dis[2005];
    for(ll i=1, x, y; i<=n;i++){
        cin >> x >> y;
        ll dx = x-x1, dy = y-y1, dx2 = x-x2, dy2=y-y2;
        dis[i].f = dx*dx+dy*dy; dis[i].s=dx2*dx2+dy2*dy2;
    }
    
    sort(dis+1, dis+n+1);
    ll ans = LLONG_MAX;
    ll mx  = 0; ll cur;
    for(ll i=n;i>0;i--){
        cur = dis[i].f;
        ans = min(ans, cur+mx);
        mx = max(mx, dis[i].s);
    }
    ans = min(ans, mx);
    cout << ans << nl;
	
	return 0;
}
 
// read the question correctly (ll vs ll)
// template by bqi343
 