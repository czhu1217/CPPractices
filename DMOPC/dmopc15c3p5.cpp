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
const ll MM = 37;
ll n, m, a[MM], ans;
map<ll, ll> mp;
int main(){
    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, m){
        ll x; cin >> x; a[i+n] = -x;
    }
    ll mid = (m+n)/2;
    ll tmp = 0;
    FOR(i, 0, (1<<mid)-1){
        tmp = 0;
        FOR(j, 0, mid){
            if(i&(1<<j)) tmp += a[j+1];
        }
        mp[tmp]++;
    }
    reverse(a+1, a+1+n+m);
    // for(auto e:mp) cout << e.f << " " << e.s << "\n";
    if((n+m)%2) mid++;
    FOR(i, 0, (1<<mid)-1){
        tmp = 0;
        FOR(j, 0, mid){
            if(i&(1<<j)) tmp += a[j+1];
        }
       ans += mp[-tmp];
    }
    cout << ans-1 << "\n";
 

    return 0;
}