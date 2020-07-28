
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
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
 
#define FOR(i, a, b) for (int i=a; i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
ll l, r, n, d[20]; ll dp[20][2520][1<<8];
ll fun(int pos, int rem, int mask, bool lim){
    if(!lim&&dp[pos][rem][mask]>=0)return dp[pos][rem][mask];
    ll res = 0;
    if(pos==0){
        for(int i=2;i<10;i++){
            if((mask&(1<<(i-2)))&&rem%i!=0)return 0;
        }
        return 1;
    }
    int up = lim?d[pos]:9;
    for(int i=0;i<=up;i++){
        int nmask = i>=2?mask|(1<<(i-2)):mask;
        res += fun(pos-1, (rem*10+i)%2520, nmask, lim&&i==d[pos]);
    }
    if(!lim)dp[pos][rem][mask]=res;
    return res;
}
ll calc(ll x){
    n = 0;
    for(;x;x/=10) d[++n]=x%10;
    return fun(n, 0, 0, 1);
}
void solve(){
    cin >> l >> r;
    cout << calc(r)-calc(l-1) << "\n";
}
int main(){
    memset(dp, -1, sizeof(dp));

    int t; cin >> t;
    while(t--)solve();
    return 0;
}