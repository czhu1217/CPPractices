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
ll n, m, k;
const ll MM = 1003;
pi a[MM]; bool vis[MM];
struct e{
    ll q, t, d, a;
} ok[MM];
ll dp[MM];ll sum;ll ans=0;
int main(){
    memset(dp, -0x3f, sizeof dp);
    cin >> n >> m >> k;

    FOR(i, 1, n)scanf("%lld %lld", &a[i].f , &a[i].s);
    FOR(i, 1, m){
        scanf("%lld %lld %lld %lld", &ok[i].q, &ok[i].t, &ok[i].d, &ok[i].a);

    }
    dp[0] =0;
    for(ll i=1;i<=n;i++){
            for(ll j=a[i].f; j<=k;j++){
                dp[j] = max(dp[j], dp[j-a[i].f]+a[i].s);
                ans = max(dp[j], ans);
            }
    }
    for(ll i=1;i<=m;i++){
        ll v = a[ok[i].t].s*(ok[i].q);
        for(ll x = 0;x<ok[i].a;x++){
            bool imp = 0;
            for(ll j=k;j>=ok[i].d;j--){
                ll ori = dp[j];
                dp[j] = max(dp[j], dp[j-ok[i].d]+v);
                ans = max(dp[j], ans);
                if(dp[j]!=ori) imp=1;
            }
            if(!imp) break;
        }
    }
    cout << ans << "\n";
    return 0;
}