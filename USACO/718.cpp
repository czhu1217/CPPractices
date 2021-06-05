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
const int MM = 1005;
int dp[MM][MM], n, a[MM], b[MM], tmp[MM];
int main(){
    ifstream cin("nocross.in");
    ofstream cout("nocross.out");
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) cin >> b[i];
    FOR(i, 1, n){
        memset(tmp, 0, sizeof tmp);
        FOR(j, 1, n){
            if(abs(a[i]-b[j])<=4){
                tmp[j] = max(tmp[j-1], max(dp[i-1][j-1]+1, dp[i-1][j]));
            }
            else tmp[j] = max(tmp[j-1], dp[i-1][j]);
        }
        FOR(j, 1, n) dp[i][j] = tmp[j];
    }
    cout << dp[n][n] << "\n";
 

    return 0;
}