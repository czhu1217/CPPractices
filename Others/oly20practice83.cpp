//bitmask dp
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
ll n, k, a[17]; ll cnt=0;
ll memo[17][262144]; bool pos[17][262144];
ll tsp(ll u, ll msk){
    if(msk==0)return 1;
    if(memo[u][msk])return memo[u][msk];
    ll ans = 0;
    for(ll i=1;(1<<(i-1))<=msk;i++){
        if((msk&(1<<(i-1)))==0){  continue;}
        ll v = i;
        if(u!=0&&abs(a[v]-a[u])<=k){continue;}
        ll prev = tsp(v, msk^(1<<(i-1)));
        if(pos[v][msk^(1<<(i-1))]){
                    ans += prev;
                    pos[u][msk]=1;
        }
    }
    memo[u][msk]=ans;
    return ans;
}
int main(){
    memset(memo, 0, sizeof memo);
    memset(pos, 0, sizeof pos);
    cin >> n >> k;
    for(ll i=1;i<=n;i++)cin >> a[i];
    for(ll i=1;i<=n;i++)pos[i][0]=1;
    cout << tsp(0, (1<<(n))-1) << "\n";
    return 0;

}