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
const ll MM = 1004;
ll n, d, cnt[MM][MM], par[MM], x, y;
ll dp[MM][MM], ans, num[MM];
struct item{
    ll k, c, v;
} a[MM];
int main(){
    // memset(dp, -0x3f, sizeof dp);
    cin >> n >> d;
    memset(dp[0], 0, sizeof dp[0]);
    FOR(i, 1, n) cin >> a[i].c >> a[i].v >> a[i].k;
    FOR(i, 1, n){
        FOR(j, 0, d) dp[i][j] = dp[i-1][j];
        for(ll j=1;j<=a[i].k;j++){
            bool imp = 0;
            for(ll t = d;t>=a[i].c;t--){
                if(dp[i][t-a[i].c]+a[i].v>dp[i][t]){
                    imp = 1;
                   dp[i][t] = dp[i][t-a[i].c]+a[i].v;
                    if(dp[i][t]>ans){
                        ans = dp[i][t];
                        x = i, y = t;
                    }
                }
            }      
            if(!imp) break; 
        }
    }
    int cost = y, val = ans;
    for(int i=x;i>0;i--){
        for(int j=0;j<=a[i].k;j++){
            if(cost-j*a[i].c>=0&&dp[i-1][cost-j*a[i].c]+j*a[i].v==val){
                num[i] = j;
                val = val - j*a[i].v;
                cost = cost - j*a[i].c;
            }
        }
    }
    cout << ans << "\n";
    FOR(i, 1, n) cout << num[i] << "\n";
    return 0;
}