
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
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
const ll MM = 1e6+6;
    ll a[MM]; 

void solve(){
    string s; cin >> s;
    a[0]=0;
    ll n = s.size();
    FOR(i, 0, s.size()-1){
        if(s[i]=='+') a[i+1] = 1;
        else a[i+1]=-1;
    }
    ll ans = 0;
    FOR(i, 1, n){
        a[i] += a[i-1];
        if(a[i]<ans) ans = a[i];
    }
    ans = -1*ans;
    ll thres = 0;
    ll res = 0;
    FOR(i, 1, n){
        if(a[i]>0)continue;
        a[i] = -1*a[i];
        if(a[i]<thres) continue;
        res += i*(a[i]-thres);
        thres = max(thres, a[i]);
    }
    res += n;
    cout << res << "\n";

}
int main(){
    ll t; cin >> t;
    while(t--)solve();
    return 0;
}
