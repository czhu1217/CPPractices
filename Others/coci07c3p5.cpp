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
#include <sstream>
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
//dp[len][left][all]
ll dp[20][140][2]; 
ll a, b, s; string str;
ll fun(ll len, ll left, bool all){
    if(len==str.size()&&left!=0) return 0;
    if(len==str.size()&&left==0){
        return 1;}
    if(left<0)return 0;
    ll &res = dp[len][left][all];
    if(res>=0)return res;
    res = 0;
    ll lim = all?9:str[len]-'0';
    for(ll i=lim;i>=0;i--){
        if(left-i>=0){ 
            res += fun(len+1, left-i, all||(i!=lim));
        }
    }
    return res;

}
string ss;
ll solve(ll n){
    ll ans=0;
    if(n<0)return 0;
    memset(dp, -1, sizeof dp);
    str = to_string(n);
    ll lim = str[0]-'0';
    for(ll i=lim;i>0;i--)
        ans += fun(1, s-i, i!=lim);
    
    for(ll k=2;k<=str.size();k++)
        for(ll i=9;i>0;i--)
            ans += fun(k, s-i, 1);

    return ans;

}
int main(){
    cin >> a >> b >> s;
    cout << solve(b) - solve(a-1) << "\n";
    ll lo = a-1, hi = b;
    while(hi-lo>1){
        ll mid = (lo+hi)/2;
        if(solve(mid) - solve(lo)>0)
            hi = mid;
        else
            lo = mid;
    }
    cout << hi << "\n";
    return 0;
}