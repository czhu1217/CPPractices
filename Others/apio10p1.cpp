
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
const ll MM = 1e6+4;
ll a, b, c, x[MM], n; ll dp[MM];
int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    memset(dp, -0x3f, sizeof dp);
    cin >> n;
    cin >> a >> b >> c;
    int jj=0;
    dp[0] = 0;
    FOR(i, 1, n) cin >> x[i];
    for(ll i=1;i<=n;i++){
        ll sum=x[i]; ll temp=0;
        for(ll j=i-1;j>=jj;j--){
            ll tt = dp[i];
            dp[i] = max(dp[i], dp[j] + a*sum*sum+b*sum+c);
            sum += x[j];
            if(dp[i]!=tt){
                temp = j;
            }
        }
        jj = temp;
    }
    cout << dp[n] << "\n";
    return 0;
}