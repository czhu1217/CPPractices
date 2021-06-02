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
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
const int MM = 11;
int n, m, c[MM], a[MM][MM], g[MM], cn[MM];
int ans = INT_MAX, tot;
int cnt[MM];
bool fun(int msk){
    tot = 0;
    memset(cnt, 0, sizeof cnt);
    FOR(i, 0, m-1){
        if((1<<i)&msk){
            FOR(j, 1, n)
                cnt[j] += a[i+1][j];
            tot += c[i+1];
        }
    }
    FOR(i, 1, n){
        if(g[i]<cnt[i]) return 0;
        tot += (g[i]-cnt[i])*cn[i];
    }
    return 1;
}
int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> m;
    FOR(i, 1, n) cin >> cn[i];
    FOR(i,1, m){
        cin >> c[i];
        FOR(j, 1, n) cin >> a[i][j];
    }
    FOR(i, 1, n) cin >> g[i];
    FOR(msk, 0, (1<<m)-1){
        if(fun(msk)) ans = min(ans, tot);
    }
    cout << ans << "\n";
    return 0;
}