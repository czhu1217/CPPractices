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
const ll MM = 1e6+5;
ll n, a[MM], dif[MM];
ll cnt=0; ll t; ll ans = LLONG_MAX, tmp; ll pre;
vector<ll> v;
int main(){
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n){
        dif[i] = (a[i] - (n-i+1) + n)%n;
        if(dif[i]>n/2) dif[i] = dif[i] - n;
    }
    sort(dif+1, dif+1+n);
    pre = dif[1];
    FOR(i, 2, n){
        if(dif[i]>pre){
            tmp = max(tmp, dif[i]-pre-1);
            pre = dif[i];
        }
    }
    tmp = max(tmp, dif[1]+(n-1)/2+n/2-dif[n]);
    ans = (n-tmp)/2;
    tmp = 0;
    FOR(i, 1, n){
        dif[i] = (a[i] - i+ n)%n;
        if(dif[i]>n/2) dif[i] = dif[i] - n;
    }
    sort(dif+1, dif+1+n);
    pre = dif[1];
    FOR(i, 2, n){
        if(dif[i]>pre){
            tmp = max(tmp, dif[i]-pre-1);
            pre = dif[i];
        }
    }
    tmp = max(tmp, dif[1]+(n-1)/2+n/2-dif[n]);
    ans = min(ans, (n-tmp)/2);
    cout << ans << "\n";
    return 0;
}