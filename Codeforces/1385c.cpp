
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
    vector<pi> v;
    ll n;
    cin >> n;

    for(ll i=1, x;i<=n;i++){
     cin >> x;
        if((!v.empty())&&x==v.back().f) v.back().s++;
        else v.pb({x, 1});
    }
    ll id = -1;
    for(ll i=0;i+2<v.size();i++){
        if(v[i+1].f<v[i].f&&v[i+1].f<v[i+2].f) id = i;
    }
    ll ans=0;
    if(id>=0){
        for(ll i=0;i<=id;i++){
            ans += v[i].s;
        }
    }
    cout << ans << "\n";
}
int main(){
    ll t; cin >> t;
    while(t--)solve();
    return 0;
}