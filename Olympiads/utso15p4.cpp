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
const int MM = 2005;
double dp[MM][MM];
int n, m, t; vector<pair<int, pi>> adj[MM];
int main(){
    memset(dp, 0, sizeof dp);
    cin >> n >> m >> t;
    int u, v, x, y;
    FOR(i, 1, m){
        cin >> u >> v >> x >> y;
        adj[u].pb({v, {x, y}});
    }
    dp[0][1] = 1; dp[1][1] = -1;
    for(int j=0;j<=t;j++){
        for(int i=1; i<=n;i++){
            if(j>0) dp[j][i] += dp[j-1][i];
            if(i==n)continue;
            for(auto e:adj[i]){
                if(j+e.s.f<=t)dp[j+e.s.f][e.f] += dp[j][i]*1/adj[i].size()*1/(e.s.s-e.s.f+1);
                if(j+e.s.s+1<=t)dp[j+e.s.s+1][e.f] -= dp[j][i]*1/adj[i].size()*1/(e.s.s-e.s.f+1);
            }
        }
    }
    double ans = 0, denom=0;
    for(int i=1;i<=t;i++){
        ans += i*dp[i][n];
        denom += dp[i][n];
    }
    ans = (double)ans/denom;
    cout <<setprecision(10)<< ans << "\n";
    return 0;
}