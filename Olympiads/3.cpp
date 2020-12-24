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
const ll MM = 1e7+5, mod = 1e9+7;
ll n, p, q, a[MM],stamp[MM], ans[MM];
int main(){
    scanf("%lld %lld %lld", &n, &p, &q);
    FOR(i, 1, n) scanf("%lld", &a[i]);ll pt = 1, days = 0, cur = 0, pre = 0, temp = 0, val, t;
    for(ll i=1;i<=n;i++){
        t = (n-i+1)*p/q;
        stamp[pre+1] = cur;
        pre = n-t;
        if(stamp[i]>0) temp = stamp[i];
        val = (a[i] + temp)%mod;
        val = (val - cur + temp)%mod;
        cur = (cur+val)%mod;
        printf("%lld ", cur);

    }
    printf("\n");
    
    return 0;
}