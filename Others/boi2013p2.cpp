
//digit dp
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
ll a, b; ll dp[20][10][10][2];
string st;
//dp[first][second][length][already smaller than original]
ll  fun(ll pos, ll last, ll second, bool all){
    if(pos>=st.size())return 1;
    ll &res = dp[pos][last][second][all];
    if(res>=0) return res;
    res = 0;
    ll lim = all?9:st[pos]-'0';
    for(ll i=0;i<=lim;i++){
        if(i!=last&&i!=second)
        res += fun(pos+1, i, last, all||(i!=lim));
    }
    return res;

}
ll solve(ll num){
    memset(dp, -1, sizeof dp);

    if(num<0)return 0;
    ll ans =1;
    st = to_string(num);
    ll lim = st[0]-'0';
    for(ll i=1;i<=lim;i++){
        ans += fun(1, i, i, i!=lim);
    }
    for(ll k=2;k<=st.size();k++){
        for(ll i=1;i<10;i++){
            ans += fun(k, i, i, 1 );
        }
    }
    return ans;
}
int main(){

    cin >> a >> b;
    cout << solve(b) - solve(a-1) << "\n";

    
    return 0;
}