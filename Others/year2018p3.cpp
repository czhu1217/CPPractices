//binary search + greedy
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
ll n, m, k, a[MM];

int main(){
    cin >> n >> m >> k;
    FOR(i, 1, n) cin >> a[i];
    ll lo = 1, hi = 2e9; ll mid;
    while(hi!=lo){
        // cout << lo << " " << hi << "\n";
        mid = ((hi+lo)/2) + (lo+hi)%2;
        queue<pi> v; ll cur = 0, cnt=0;
        FOR(i, 1, n){
            while(!v.empty()&&v.front().f+m-1<i){
                cur -= v.front().s;
                v.pop();
            }
            if((mid - a[i]) - cur <= 0) continue;
            else{
                v.push({i, (mid - a[i]) - cur});
                cnt += (mid - a[i]) - cur;
                cur += (mid - a[i]) - cur;
            }
            // cout << mid << "\n";
        }
        if(cnt>k) hi = mid-1;
        else lo = mid;
    }
    cout << hi << "\n";

    return 0;
}
