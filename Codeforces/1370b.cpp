
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
vi ev, od;

    ll n, a[2004];
    cin >> n;
    n *= 2;
    for(ll i=1;i<=n;i++) cin >> a[i];
    FOR(i, 1, n){
        if(a[i]%2) od.pb(i); else ev.pb(i);
    }


    if(od.size()%2){
        od.pop_back(); ev.pop_back();
    }
    else{
        if(od.size()>=2){od.pop_back();od.pop_back();}
        else{ev.pop_back();ev.pop_back();}
    }
    if(!od.empty()){
    for(ll i=0;i<od.size()-1; i+=2){
        cout << od[i] << " " << od[i+1] << "\n";
    }
    }
    if(!ev.empty()){
    for(ll i=0;i<ev.size()-1; i+=2){
        cout << ev[i] << " " << ev[i+1] << "\n";
    }
    }


}
int main(){
    ll t; cin >> t;
    while(t--)solve();
    return 0;
}