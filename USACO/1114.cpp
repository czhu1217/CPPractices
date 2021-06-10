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
const int MM = 305;
int n, a[MM], dp[MM][MM];
int main(){
    memset(dp, 0x3f, sizeof dp);
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) dp[i][i] = 1;
    FOR(i, 1, n-1){
        FOR(j, 1, n-i){
            if(a[j]==a[i+j]){
                dp[j][i+j] = min(dp[j+1][i+j-1]+1, min(dp[j][i+j-1], dp[j+1][i+j]));

            }
            else{
                FOR(k, j, i+j-1){
                    dp[j][i+j] = min(dp[j][i+j], dp[j][k]+dp[k+1][i+j]);

                }
            }

        }
    }
    cout << dp[1][n] << "\n";

    return 0;
}