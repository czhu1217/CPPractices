
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
string str;
ll l, r;
ll dp[10][2][10];
ll fun(int len, bool all, int dig){
    if(len==str.size())return 1;
    ll &res = dp[len][all][dig];
    if(res>=0)return res;
    res = 0;
    int lim = all?9:str[len]-'0';
    for(int i=0;i<=lim;i++){
        if(abs(dig-i)>=2){
            res += fun(len+1, all||i!=lim, i);
        }
    }
    return res;
}
ll solve(ll k){
    if(k<=0)return 0;
    ll ans=0;
    memset(dp, -1, sizeof dp);
    str = to_string(k);
    int lim = str[0] - '0';
    for(int i=1;i<=lim;i++){
        ans += fun(1, lim!=i, i);
    }
    for(int k=2;k<=str.size();k++){
        for(int i=1;i<10;i++){
            ans += fun(k, 1, i);
        }
    }
    return ans;


}
int main(){
    cin >> l >> r;
    cout << solve(r)-solve(l-1) << "\n";
    
    return 0;
}