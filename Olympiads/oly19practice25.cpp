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
const ll MM = 5005;
ll n, m, k, q;
ll dif[MM][MM];
int main(){
    cin >> n >> m >> k;
    ll a, b, c, d;
    FOR(i, 1, k){
        cin >> a >> b >> c >> d;
        dif[a][b]++; dif[c+1][d+1]++;
        dif[a][d+1]--; dif[c+1][b]--;
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            dif[i][j] += dif[i-1][j]+dif[i][j-1]-dif[i-1][j-1];
        }
    }
    // FOR(i, 1, n){ FOR(j, 1, m) cout << dif[i][j] << " "; cout << "\n";}
    // cout << "\n";
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            dif[i][j] += dif[i-1][j]+dif[i][j-1]-dif[i-1][j-1];
        }
    }
        // FOR(i, 1, n){ FOR(j, 1, m) cout << dif[i][j] << " "; cout << "\n";}
    cin >> q;
    while(q--){
        cin >> a >> b >> c >> d;
        cout << dif[c][d]-dif[a-1][d]-dif[c][b-1]+dif[a-1][b-1] << "\n";
    }
    return 0;
}