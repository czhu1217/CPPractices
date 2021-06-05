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
const int MM = 250;
int n, a[MM], dp[MM][MM]; bool pos[MM][MM];
int main(){
	freopen("248.in", "r", stdin);
	freopen("248.out", "w", stdout);
	// cin reads from the file instead of standar
    memset(dp, -1, sizeof dp);
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &a[i]);
    FOR(i, 1, n){
        pos[i][i] = 1; dp[i][i] = a[i];
    }
    FOR(i, 1, n-1){
        FOR(j, 1, n-i){
            FOR(k, j, i+j-1){
                if(pos[j][k]&&pos[k+1][i+j]&&(dp[j][k]==dp[k+1][i+j])){
                    pos[j][i+j] = 1;
                    dp[j][i+j] = dp[j][k]+1;
                }
                else{
                    dp[j][i+j] = max(dp[j][i+j], max(dp[j][k], dp[k+1][i+j]));
                }
            }
        }
    }
    printf("%d\n", dp[1][n]);

 

    return 0;
}