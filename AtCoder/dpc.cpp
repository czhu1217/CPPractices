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
const int MM = 1e5+5;
int n, a[4][MM]; ll dp[4][MM];
int main(){
    cin >> n;
    FOR(i, 1, n) cin >> a[0][i] >> a[1][i] >> a[2][i];
    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++){
            dp[j][i] = max(dp[(j+1)%3][i-1], dp[(j+2)%3][i-1]) + a[j][i];
        }
    }
    ll ans=0;
    for(int i=0;i<3;i++){
        ans = max(ans, dp[i][n]);
    }
    cout << ans << "\n";

    return 0;
}