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
const int MM = 22, lim = 2100000, mod = 1e9+7;
int n; bool a[MM][MM]; int dp[MM][lim]; ll cnt;
int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    dp[0][0] = 1; a[0][0] = 1;
    FOR(i, 1, n)
        FOR(j, 1, n)
            cin >> a[i][j];
            
    for(int i=1;i<=n;i++){
        for(int msk = 0; msk<(1<<n);msk++){
            if(__builtin_popcount(msk)!=i) continue;
            for(int j=0;j<n;j++){
                if((msk&(1<<j))&&a[i][j+1]){
                    dp[i][msk] += dp[i-1][msk^(1<<j)];
                    dp[i][msk] %= mod;
                }
            }
        }
    }
    
    cout << dp[n][(1<<n)-1] << "\n";
    return 0;
}