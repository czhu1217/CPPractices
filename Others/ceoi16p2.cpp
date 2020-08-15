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
const int MM = 2005, mod = 1e9+7;
//dp[i][number of free components]
ll n, dp[MM][MM], s, e;
int main(){
    memset(dp, 0, sizeof dp);
    cin >> n >> s >> e;
    dp[0][0]=1;
    for(int i=1;i<n;++i){
      for(int j=0;j<i;++j) 
      {
          if(dp[i-1][j]==0)continue;
          if(i!=s&&i!=e)
          {
              dp[i][j+1]=(dp[i][j+1]+dp[i-1][j])%mod;
            if(j)
                dp[i][j-1]=(((dp[i][j-1]+(((dp[i-1][j]*j)%mod)*(j-1))%mod)+(dp[i-1][j]*j*(i>s))%mod+(dp[i-1][j]*j*(i>e))%mod)%mod);

        }
        else
        {
            dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
            if(j)
                dp[i][j-1]=(dp[i][j-1]+dp[i-1][j]*j%mod)%mod;
        }
      }
    }
    cout << dp[n-1][0] << "\n" ;
    return 0;
}