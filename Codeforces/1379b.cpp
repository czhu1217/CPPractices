
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
    //(m+c-b)%a==0;
    ll l, r; ll m; ll a, b,c;
    cin >> l >> r >> m;
    ll lim = r-l, rem;
    for(ll a=l;a<=r;a++){
        ll dif = m%a;
        if(m>=a){
            if(dif<=lim){
                b = r; c = b-dif;
                printf("%lld %lld %lld\n", a, b, c);
                return;
            }
            dif = a-dif;
            if(dif<=lim){
                c = r; b = c-dif;
                printf("%lld %lld %lld\n", a, b, c);
                return;
            }
        }
        else{
            dif = a-m;
            if(dif<=lim){
                c = r; b = r-dif;
                printf("%lld %lld %lld\n", a, b, c);
                return;
            }
        }

    }

}
int main(){
    ll t; cin >> t;
    while(t--)solve();
    return 0;
}