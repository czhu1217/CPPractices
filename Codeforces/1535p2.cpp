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
int n, a[MM];
void solve(){
    ll ans = 0;
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n){
        if(a[i]%2==0) even.pb(a[i]);
        else odd.pb(a[i]);
    }
    for(auto e:even) odd.push_front(e);
    FOR(i, 0, odd.size()-1){
        FOR(j, i+1, odd.size()-1){
            if(__gcd(odd[i], odd[j]*2)>1) ans++;
        }
    }
    cout << ans << "\n";





}
int main(){
    int t; cin >> t;
    while(t--)solve();
    return 0;
}