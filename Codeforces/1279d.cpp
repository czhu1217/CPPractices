//modular arithmetic
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
const int MM = 1e6+5, mod = 998244353;
int n, k, x, cnt[MM];
vector<int> v[MM];
ll inv[MM];
ll quick_pow(ll x, int exp){
    if(exp==0)return 1;
    ll t = quick_pow(x, exp/2);
    t = t*t%mod;
    return (exp&1)?t*x%mod:t;
}

ll mul(ll a, ll b){
    return (a*b)%mod;
}
ll add(ll a, ll b){
    return (a+b)%mod;
}

int main(){
    cin >> n;
    FOR(i, 1, n){
        cin >> k;
        FOR(j, 1, k){
            cin >> x;
            v[i].pb(x);
            cnt[x]++;

        }
    }
    FOR(i, 1, MM-1){
        inv[i] = quick_pow(i, mod-2);
    }
    ll ans=0;
    FOR(i, 1, n){
        FOR(j, 0, v[i].size()-1){
            ans = add(ans, mul(mul(inv[n], inv[v[i].size()]), mul(cnt[v[i][j]], inv[n])));
        }
    }
    cout << ans << "\n";
    return 0;
}