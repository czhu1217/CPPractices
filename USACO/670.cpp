//16 december gold
//cow checklist

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
ll H, G, dp[MM][MM][2];
pi h[MM], g[MM];
void fun(int x, int y, bool atH){
    if(dp[x][y][atH]>=0) return;
    if(x==0||y<0) return;

    dp[x][y][atH] = INT_MAX;
    if(atH){
         fun(x-1, y, 1);
        if(dp[x-1][y][1]>=0) 
        dp[x][y][atH] = dp[x-1][y][1] + (h[x].f-h[x-1].f)*(h[x].f-h[x-1].f)+(h[x].s-h[x-1].s)*(h[x].s-h[x-1].s);
        fun(x, y-1, 0);
        if(dp[x][y-1][0]>=0)
        dp[x][y][atH] = min(dp[x][y][atH], dp[x][y-1][0]+(h[x].f-g[y-1].f)*(h[x].f-g[y-1].f) + (h[x].s-g[y-1].s)*(h[x].s-g[y-1].s));
    }
    else{
         fun(x-1, y, 1);
        if(dp[x-1][y][1]>=0) 
        dp[x][y][atH] = dp[x-1][y][1] + (g[y].f-h[x-1].f)*(g[y].f-h[x-1].f)+(g[y].s-h[x-1].s)*(g[y].s-h[x-1].s);
        fun(x, y-1, 0);
        if(dp[x][y-1][0]>=0)
        dp[x][y][atH] = min(dp[x][y][atH], dp[x][y-1][0]+(g[y].f-g[y-1].f)*(g[y].f-g[y-1].f) + (g[y].s-g[y-1].s)*(g[y].s-g[y-1].s));
    }
}
int main(){
    ifstream cin("checklist.in");
    ofstream cout("checklist.out");
    memset(dp, -1, sizeof dp);
    cin >> H >> G;
    FOR(i, 0, H-1) cin >> h[i].f >> h[i].s;
    FOR(i, 0, G-1) cin >> g[i].f >> g[i].s;
    dp[0][0][1] = 0;
    int x = H-1, y = G;
    fun(x-1, y, 1);
    if(dp[x-1][y][1]>=0) 
    dp[x][y][1] = dp[x-1][y][1] + (h[x].f-h[x-1].f)*(h[x].f-h[x-1].f)+(h[x].s-h[x-1].s)*(h[x].s-h[x-1].s);
    fun(x, y-1, 0);
    if(dp[x][y-1][0]>=0)
    dp[x][y][1] = min(dp[x][y][1], dp[x][y-1][0]+(h[x].f-g[y-1].f)*(h[x].f-g[y-1].f) + (h[x].s-g[y-1].s)*(h[x].s-g[y-1].s));
    cout << dp[x][y][1];

 

    return 0;
}