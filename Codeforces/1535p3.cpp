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
const int MM = 2e5+5;
int n, dp[MM][3]; string s;
void solve(){
    memset(dp, 0, sizeof dp);
    ll ans = 0;
    cin >> s;
    n = s.size();
    int id;
    FOR(i, 1, n){
        id = i-1;
        if(s[id]=='?'){
            dp[i][2] = dp[i-1][2]+1;
            dp[i][0] = dp[i-1][1];
            dp[i][1] = dp[i-1][0];

        }
        else if(s[id]=='1'){
            dp[i][1] = dp[i-1][0]+1 + dp[i-1][2];
        }
        else{
            dp[i][0] = dp[i-1][1] + 1 + dp[i-1][2];
        }
        ans += dp[i][0] + dp[i][1] + dp[i][2];
    }
    // FOR(i, 0, 2){
    //     FOR(j, 1, n){
    //         cout << dp[j][i] << " ";
    //     }
    //     cout << "\n";
    // }
    cout << ans << "\n";
    



}
int main(){
    int t; cin >> t;
    while(t--)solve();
    return 0;
};