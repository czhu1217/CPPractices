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
const int MM = 1026;
int l, r, w, dp[MM][MM], a[11], b[11];
void fun(int mskl, int mskr){
    if(dp[mskl][mskr]>=0||dp[mskl][mskr]==-1) return;
    if(mskl==(1<<l)-1&&mskr==(1<<r)-1){dp[mskl][mskr] = 0; return;}
    int lsum = 0, rsum = 0;
    int ans = INT_MAX;
    FOR(i, 1, l){
        if(!((1<<(i-1))&mskl))  lsum += a[i];
    }
    FOR(i, 1, r){
        if(!((1<<(i-1))&mskr)) rsum += b[i];
    }

    if(abs(lsum-rsum)>w){
        dp[mskl][mskr] = -1; return;
    }
    FOR(i, 1, r){
        if(!((1<<(i-1))&mskr)){
            fun(mskl, (1<<(i-1))&mskr);
            if(dp[mskl][(1<<(i-1))&mskr]>=0) ans = min(ans, dp[mskl][(1<<(i-1))&mskr]+1);
        }
    }
    FOR(i, 1, l){
        if(!((1<<(i-1))&mskl)){
            fun((1<<(i-1))&mskl, mskr);
            if(dp[(1<<(i-1))&mskl][mskr]>=0) ans = min(ans, dp[(1<<(i-1))&mskl][mskr]+1);
        }
    }
    dp[mskl][mskr] = ans;

}
int main(){
    memset(dp, -2, sizeof dp);
    cin >> l >> r >> w;
    FOR(i, 1, l) cin >> a[i];
    FOR(i, 1, r) cin >> b[i];
    fun(0, 0);
    cout << dp[0][0] << "\n";
 

    return 0;
}