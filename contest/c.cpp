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
const ll MM = 1e6+5, mod = 1e9+9;
ll n; ll d, a[MM], dp[MM];
ll idx = 1;
int main(){
    cin >> n >> d;
    FOR(i, 1, n) cin >> a[i];
    sort(a+1, a+1+n);
    dp[0] = 1;
    FOR(i, 1, n){
        while(a[idx]<a[i]-d) idx++;
        dp[i] = (dp[i-1]*(i-idx+1))%mod;
    }
    cout << dp[n] << "\n";

 

    return 0;
}