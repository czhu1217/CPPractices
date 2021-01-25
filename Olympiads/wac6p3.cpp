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
const ll MM = 2e5+5, LOG=18;
ll n; ll a[MM], dif[MM], tar, mx, b[MM], st[LOG][MM];
map<ll, ll> ind;
ll rmq(ll x, ll y){
    ll lvl = log2(y-x+1);
    return max(st[lvl][x], st[lvl][y-(1<<lvl)+1]);
}
int main(){
    cin >> n;
    FOR(i, 1, n){
        cin >> a[i];
        b[i] = a[i];
    } 
    sort(b+1, b+n+1);
    FOR(i, 1, n) ind[b[i]] = i;
    FOR(i, 1, n-1){
        dif[i] = b[i+1]-b[i];
        st[0][i] = dif[i];
    }
    for(ll i=1;i<LOG;i++){
        for(ll j=1;j+(1<<i)-1<=n;j++){
            st[i][j] = max(st[i-1][j], st[i-1][j+(1<<(i-1))]);
        }
    }
    ll sta, end;
    FOR(i, 1, n){
        sta = i; end = ind[a[i]];
        if(sta>end) swap(sta, end);
        if(sta==end) continue;
        mx = max(mx, rmq(sta, end-1));
    }
    cout << mx << "\n";
    // FOR(i, 1, n-1) cout << dif[i] << " ";
    // cout << "\n";

    return 0;
}