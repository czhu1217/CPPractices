
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
const int MM = 1e4+4;
int n, s; int t[MM], f[MM], dp[MM], psaf[MM], psat[MM], cnt[MM];
int main(){
    ll ans = 0;
    memset(dp, 0x3f, sizeof dp);
    cin >> n >> s;
    psaf[0] = 0; psat[0]= 0;
    for(int i=1;i<=n;i++){
        cin >> t[i] >> f[i];
        psaf[i] = psaf[i-1]+f[i]; psat[i] = psat[i-1]+t[i];
    }
    dp[n+1] = 0;int jj=n+1;
    for(int i=n;i>0;i--){ int temp=0;
        for(int j = i+1;j<=jj;j++){
            ll tt = dp[i];
            dp[i] = min(dp[i], dp[j] + (s+psat[j-1]-psat[i-1])*(psaf[n]-psaf[i-1]));
            if(dp[i]!=tt)  temp = j;
        }
        jj = temp;
    }
    cout << dp[1] << "\n";


    return 0;
}