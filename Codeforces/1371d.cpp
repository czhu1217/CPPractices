
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
void solve(){
    ll cnt=0;
    ll n, k; cin >> n >> k;
    ll a[303][303], r[303], cntr[303], cntc[303];
    memset(a, 0, sizeof a);
    ll mx = k/n;
    ll ex = k - mx*n;
    for(ll i=1;i<=n;i++) r[i] = mx;
    for(ll i=1;i<=ex;i++){
        r[i]++;
    }
    vpi c;
    for(int i=1;i<=n;i++) c.pb({0, i});
    for(ll i=1;i<=n;i++){
            int cnt=0;
            sort(c.begin(), c.end());
            for(int j=0;j<c.size();j++){
                if(cnt>=r[i]) break;
                cnt++;
                a[i][c[j].s] = 1;
                c[j].f++;

            }
    }
    if(ex==0)cout << 0 << "\n"; else cout << 2 << "\n";
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            cout << a[i][j];
        }
        cout << "\n";
    }
}
int main(){
    ll t; cin >> t;
    while(t--)solve();
    return 0;
}