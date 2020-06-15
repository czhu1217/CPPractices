
#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <string>
#include <climits>
#define f first
#define s second
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
const ll MOD = 1e9+7, MM = 5e5+5;
ll n, v[MM], d[MM];
pi p[MM];
ll ans=0;
void solve(){
    cin >> n;
    for(ll i=1;i<=n;i++){
        cin >> v[i] >> d[i];
        p[i] = {d[i], v[i]};
    }
    sort(p+1, p+1+n);
    reverse(p+1, p+1+n);
    for(ll i=1;i<=n;i++){
        ans += p[i].s-max((i-2),(ll) 0)*p[i].f;
        ans = (ans+MOD)%MOD;
    }

    ans = (ans+MOD)%MOD;
    cout << ans << "\n";

    

}
int main(){
    solve();
    return 0;
}