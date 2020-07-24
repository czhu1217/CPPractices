
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
const int LOG = 1e9+7;
string k; int d;
int dp[10005][2][102];
int fun(int len, bool all, int sum){
    if(len==k.length()){
        if(sum)return 0;
        return 1;
    }
    int &res = dp[len][all][sum];
    if(res>=0) return res;
    res = 0;
    int lim = all?9:k[len]-'0';
    for(int i=0;i<=lim;i++){
        res += fun(len+1, all||i!=lim, (sum+i)%d);
        res%=LOG;
    }
    return res;


}
int solve(string k){
    memset(dp, -1, sizeof dp);
    string str = k;
    int ans=0;
    int lim = k[0]-'0';
    for(int i=1;i<=lim;i++){
        ans += fun(1, lim!=i, i%d); ans %= LOG;
    }
    for(int k=2;k<=str.length();k++){
        for(int i=1;i<10;i++){
            ans += fun(k, 1, i%d);
            ans %= LOG;
        }
    }
    return ans;



}
int main(){
    cin >> k >> d;
    cout << solve(k) << "\n";

    return 0;
}