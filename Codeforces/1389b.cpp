
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
const ll MM = 1e5+5;
ll dpp[6], dpc[6];
void solve(){
    ll ans=0;
    memset(dpc, 0, sizeof dpc);
    memset(dpp, 0, sizeof dpp);
    ll n, k, z; cin >> n >> k >> z;
    vector<ll> a; a.resize(n+1);
    FOR(i, 1, n) cin >> a[i];
    dpp[0] = a[1];
    for(ll i=2;i<=n;i++){
        // cout << i <<  "\n";
        for(ll j=0;j<=z;j++){
            if(i-1+j*2>k) continue;
            for(ll x = 0;x<=j;x++){
                dpc[j] = max(dpc[j], dpp[x]+(a[i]+a[i-1])*(j-x)+a[i]);
            }
            if(i-1+j*2==k-1){
                if(j<z)
                ans = max(ans, max(dpc[j]+a[i-1], dpc[j]+a[i+1]));
                else ans = max(ans, dpc[j]+a[i+1]);
            }
            else if(i-1+j*2==k){
                ans = max(ans, dpc[j]);
            }
            // cout << j << " " << dpc[j] << "\n";
        }
        swap(dpp, dpc);
    }
    
    cout << ans << "\n";
}
int main(){
    ll t; cin >> t;
    while(t--)solve();
    return 0;
}