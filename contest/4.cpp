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
ll dp[MM], dp1[MM];ll sum;ll ans=0;
int main(){
    memset(dp, -0x3f, sizeof dp);
    cin >> n >> m >> k;

    FOR(i, 1, n)scanf("%lld %lld", &a[i].f , &a[i].s);
    FOR(i, 1, m){
        scanf("%lld %lld %lld %lld", &ok[i].q, &ok[i].t, &ok[i].d, &ok[i].a);

    }
    dp[0] =0;
    for(ll i=1;i<=n;i++){
            for(int j=a[i].s;)
    }
    cout << ans << "\n";
    int cnt[MM];
    for(ll i=1;i<=m;i++){
        memset(cnt, 0, sizeof cnt);
        ll v = a[ok[i].t].s*(ok[i].q);
        for(int j=ok[i].d;j<=k;j++){
            if(cnt[j-ok[i].d]>=ok[i].a)continue;
            if(dp[j-ok[i].d]+v==dp[j]){
                cnt[j] = min(cnt[j], cnt[j-ok[i].d]+1);
            }
            if(dp[j-ok[i].d]+v>dp[j]){
                dp[j] = dp[j-ok[i].d]+v;
                cnt[j] = cnt[j-ok[i].d]+1;
            }

        }
    }
    for(int i=0;i<=k;i++){
        ans = max(ans, dp[i]);
    }
    cout << ans << "\n";
    return 0;
}