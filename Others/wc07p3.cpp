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
const int MM = 20, mod = 13371337, M = (1<<16);
int adj[MM][MM],dp[MM][M];
int n; bool vis[MM];
int dfs(int u, int msk){
    if(dp[u][msk]) {
        return dp[u][msk];
    }
    int cnt = 0;
    if(u==n){
         return 1;}
    FOR(i, 1, n){
        if(adj[u][i]&&(!((1<<(i-1))&msk))) 
        cnt += dfs(i, msk|(1<<i-1));
        cnt %= mod;
    }
    dp[u][msk] = cnt;
    return cnt;

}
void solve(){
    memset(dp, 0, sizeof dp);
    cin >> n;
    FOR(i, 1, n) FOR(j, 1, n) cin >> adj[i][j];
    dfs(1,1);
    cout << dp[1][1] << "\n";


}
int main(){
    int t; cin >> t;
    while(t--)solve();
    return 0;
}