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
const int mod = 1e9+7;
ll quick_pow(ll x, int exp, int mod){
    if(exp==0)return 1;
    ll t = quick_pow(x, exp/2, mod);
    t = t*t%mod;
    return (exp&1)?t*x%mod:t;
}
void solve(){
    ll a, b, c;
    cin >> a >> b >> c;
    b = quick_pow(b, c, mod-1);
    a = quick_pow(a, b, mod);
    cout << a << "\n";

}
int main(){
    int t; cin >> t;
    while(t--)solve();
    return 0;
}