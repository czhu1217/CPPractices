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
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
const int MM = 5005;
string a, bi;
int cnt;
int dp[MM][MM]; bool vis[MM][MM];
void fun(int x, int y){
    if(vis[x][y]) return;
    vis[x][y] = 1;
    if(x==0 || y==0){ dp[x][y] = x+y; return;}
    if(a[x-1]==bi[y-1]){
        fun(x-1, y-1); dp[x][y] = dp[x-1][y-1];
    }
    else{
        fun(x-1, y); fun(x, y-1); fun(x-1, y-1);
        dp[x][y] = min(dp[x-1][y], min( dp[x][y-1], dp[x-1][y-1]))+1;
    }




}
int main(){
    memset(dp, 0x3f, sizeof dp);
    cin >> a >> bi ;
    
    fun(a.size(), bi.size());
    cout << dp[a.size()][bi.size()] << "\n";
    

    return 0;
}