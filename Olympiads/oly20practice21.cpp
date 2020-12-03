//interval dp
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
const int MM = 202;
int n, len, x[MM], t[MM], dp[MM][MM][MM][2];ll ans;
int main(){
    cin >> n >> len; memset(dp, 0x3f, sizeof dp);
    FOR(i, 1, n) cin >> x[i];
    FOR(i, 1, n) cin >> t[i];
    dp[n+1][0][0][0] = 0; x[n+1] = len;
    for(int l=n+1;l>0;l--){
        for(int r = 0; r<l;r++){
            for(int k=0;k<=n-l+r+1;k++){
                int ti = min(dp[l][r][k][0]+x[l]-x[l-1], dp[l][r][k][1]+len-(x[l-1]-x[r]));
                int d = ti<=t[l-1]?1:0;
                dp[l-1][r][k+d][0] = min(ti, dp[l-1][r][k+d][0]);
                ti = min(dp[l][r][k][1]+(x[r+1]-x[r]), dp[l][r][k][0]+len-(x[l]-x[r+1]));
                d = ti<=t[r+1]?1:0;
                dp[l][r+1][k+d][1] = min(ti, dp[l][r+1][k+d][1]);

            }
        }
    }
    int inf = 0x3f3f3f3f;
    for(int l=n+1;l>0;l--)
        for(int r = 0; r<l;r++)
            for(int k=0;k<=n-l+r+1;k++)
                if(dp[l][r][k][0]<inf||dp[l][r][k][1]<inf) ans = max(ans, (ll)k);
    cout << ans << "\n";
    return 0;
}