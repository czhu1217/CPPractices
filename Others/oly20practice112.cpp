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
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
const int MM = 302;
char s[302];
int p, n, k, c[MM], v[MM], rem;
ll dp[MM][MM][1<<8], mx[2]; 
int main(){
    memset(dp, -0x3f, sizeof(dp));
    cin >> n >> k; scanf("%s", s+1);
    FOR(i, 1, n) dp[i][i][s[i]-'0'] = 0;
    FOR(i, 0, (1<<k)-1) cin >> c[i] >> v[i];
    for(int len = 1; len<n;len++){
        for(int l = 1; l+len<=n;l++){
            int r = l+len; rem = len%(k-1);
            if(!rem) rem = k-1;
            for(int mid=r; mid>l;mid-=(k-1)){
                for(int p=0; p<(1<<rem);p++){
                    dp[l][r][p<<1 | 0] = max(dp[l][r][p<<1 | 0], dp[l][mid-1][p] + dp[mid][r][0]);
                    dp[l][r][p<<1 | 1] = max(dp[l][r][p<<1 | 1], dp[l][mid-1][p] + dp[mid][r][1]);
                }
            }
            if(rem==k-1){
                mx[0]=mx[1]=-1e18;
                for(int p=0;p<(1<<k);p++){
                    mx[c[p]] = max(mx[c[p]], dp[l][r][p]+v[p]);
                }
                dp[l][r][0] = mx[0]; dp[l][r][1] = mx[1];
            }
        }
    }
    ll ans = -1e18;
    for(int p=0;p<(1<<k);p++){
        ans = max(ans, dp[1][n][p]);
    }
    cout << ans << "\n";
    return 0;
}