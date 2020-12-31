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
const ll MM = 1414214+5;
ll n, q, x, y, loc[MM];
int main(){
    cin >> n >> q;
    FOR(i, 1, n){
        cin >> x >> y;
        ll t = ceil(sqrt(x*x+y*y));
        loc[t]++;
    }
    FOR(i, 1, MM-1) loc[i] += loc[i-1];
    ll r;
    FOR(i, 1, q){
        cin >> r;
        cout << loc[r] << "\n";
    }
    return 0;
}