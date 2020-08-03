
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
ll n, k, a[MM], b[MM], dif[MM], psa[MM];
int main(){
    cin >> n >> k;
    for(ll i=1;i<=n;i++) cin >> a[i];
    for(ll i=1;i<=n;i++) cin >> b[i];
    for(ll i=1;i<=n;i++){
        dif[i] = b[i]-a[i];
    }
    sort(dif+1, dif+1+n);
    ll len = n-k;
    for(ll i=1;i<=n;i++){
        psa[i] = psa[i-1]+dif[i];
    }
    ll ans = LLONG_MAX;
    // for(ll i=1;i<=n;i++)cout << dif[i] << " ";
    for(ll i=1;i+len-1<=n;i++){
         ll res;
        if(len%2){
            res = psa[i+len-1]-psa[(i+i+len-1)/2] - psa[(i+i+len-1)/2-1] + psa[i-1];
        }
        else{
            res = psa[i+len-1]-psa[(i+i+len-1)/2]-psa[(i+i+len-1)/2]+psa[i-1];
        }
        ans = min(ans, res);
    }
    cout << ans << "\n";

    return 0;
}