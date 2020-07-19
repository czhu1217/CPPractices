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
const ll MM = 303, mod = 1e9+7;
 ll a[MM][MM], dp[MM], cnt[MM][MM];
ll n, r, c;
ll dfs(ll i, ll j, ll val){

    val *= a[i][j];

    ll ans=0;
    if(val>=n){
        return cnt[i][j];
    }
    if(i+1<=r) ans += dfs(i+1, j, val);
    if(j+1<=c) ans += dfs(i, j+1, val);
    return ans;

}

int main(){
    cin >> r >> c >> n;
    cnt[1][1] = 1;
    for(ll i=1;i<=r;i++){
        for(ll j=1;j<=c;j++){
            cin >> a[i][j];
        }
    }
    cnt[r][c] = 1;
    for(int i=r;i>0;i--) for(int j=c;j>0;j--) if(i!=r||j!=c) cnt[i][j] = (cnt[i+1][j]+cnt[i][j+1])%mod;

    cout << dfs(1, 1, 1) << "\n";
    return 0;
}
