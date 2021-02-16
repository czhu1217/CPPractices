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
const int MM = 3000;
int n;
double a[MM], dp[MM][MM];

int main(){
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    dp[1][1] = a[1]; dp[1][0] = 1-a[1];
    FOR(i, 2, n){
        FOR(j, 0, i){
            dp[i][j] += (1-a[i])*dp[i-1][j];
            if(j)
            dp[i][j] += a[i]*dp[i-1][j-1];
        }
    }
    double ans = 0;
    FOR(i, ceil(n*1.0/2.0), n){
        // cout << dp[n][i] << " ";
        ans += dp[n][i];
    }
    printf("%.10f\n", ans);
    return 0;   
}