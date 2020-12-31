#include <bits/stdc++.h>
using namespace std; 
typedef unsigned long long ll;
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
const int MM = 5e5+5, mod=1e9+7;
ll n; ll a[MM], cach[65]; int mx=0;
ll quick_pow(ll x, ll exp){
    if(exp==0)return 1;
    ll t = quick_pow(x, exp/2);
    t = t*t%mod;
    return (exp&1)?t*x%mod:t;
}
void solve(){
    mx = 0;
    memset(cach , 0, sizeof cach);
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n){
        for(int j=0;j<=61;j++){
             if(((ll)1<<j)&a[i]){
                 cach[j]++;
             } 
        }
    }
    ll ans=0;
    FOR(i,1,n){
        ll an=0, o=0;
        for(ll j=0;j<=61;j++){
            if((((ll)1<<j))&a[i]){
                o += n*(((ll)1<<j)%mod);
                o %= mod;
                an += ((((ll)1<<j)%mod)*cach[j])%mod;
                an %= mod;
            }
            else if(cach[j]){
                o += (((ll)1<<j)%mod*cach[j])%mod;
                o %= mod;
            }
        }
        // cout << o <<  " " << an << "\n";
        ans = (ans+(o*an)%mod)%mod;
    }
    cout << ans << "\n";


}
int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    ll t; cin >> t;
    while(t--)solve();
    return 0;
}