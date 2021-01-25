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
const ll MM = 1e5+5;
ll n, k, r; bool a[MM];
ll t, cnt, ans;
int main(){
    cin >> n >> k >> r;
    FOR(i,1,k){
        cin >> t;
        a[t]=1;
    }
    FOR(i, 1, r){
        if(a[i]) cnt++;
    }
    for(ll i=r;i>0;i--){
        if(cnt>=2) break;
        if(!a[i]){
            a[i] = 1;
            cnt++;
            ans++;
        }
    }
    for(ll i=r+1;i<=n;i++){
        cnt -= a[i-r];
        cnt += a[i];
        if(cnt<2){
            a[i] = 1;
            ans++;
            cnt++;
        } 
    }
    cout << ans << "\n";
    return 0;
}