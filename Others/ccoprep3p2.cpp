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
const ll MM = 2e6+6;
ll n, l; ll dp[MM]; ll a[MM];
deque<ll> dq; ll psa[MM];
ll p(ll base){ return base*base;}
ld slope(ll j, ll k){
    return (ld)(p(psa[j])-p(psa[k])+p(j)-p(k)+2*(j*psa[j]-k*psa[k]+psa[j]-psa[k]+l*psa[j]-l*psa[k]+j-k+l*j-l*k)+dp[j]-dp[k])/(ld)(2*(ld)(psa[j]-psa[k]+j-k));
}
int main(){
    // cin.tie(0); cin.sync_with_stdio(0);
    
    cin >> n >> l;
    for(int i=1;i<=n;i++) dp[i] = LLONG_MAX;
    psa[0]=0;
    for(ll i=1;i<=n;i++){cin >> a[i]; psa[i] = psa[i-1]+a[i];}
    dp[0] = 0; dq.pb(0);
    for(ll i=1;i<=n;i++){
        while((!dq.empty())&&dq.size()>=2&&slope(dq[0], dq[1])<=psa[i]+i){
           dq.pop_front();
        }
        ll j = dq[0]; ll tt = (psa[i]-psa[j]+i-j-1-l);
        dp[i] = dp[j] + tt*tt;
        while((!dq.empty())&&dq.size()>=2&&slope(dq[dq.size()-2], dq[dq.size()-1])>=slope(dq[dq.size()-1], i)) dq.pop_back();
        dq.pb(i);
    }
    //  for(ll i=1;i<=n;i++) cout << dp[i] << " ";
    cout << dp[n] << "\n";
    return 0;
}