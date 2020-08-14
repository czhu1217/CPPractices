
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
#include <stack>
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
const int MM = 505;
int n, m, k;
int p[MM], b[MM], dp[MM][MM];
int sum=0;
int main(){
    memset(dp, 0, sizeof dp);
    cin >> n >> m >> k;
    FOR(i, 1, n){
        cin >> p[i];}
    FOR(i, 0, m) cin >> b[i];
    FOR(i, 1, n) sum += b[p[i]];
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            for(int x=0; x<=j;x++){
                if(p[i]+x>m)break;
                dp[i][j] = max(dp[i][j], dp[i-1][j-x]+b[p[i]+x]-b[p[i]]);
            }
                // cout << dp[i][j] << " ";

        }
        // cout <<a "\n";
    }
    cout << sum+dp[n][k] << "\n";


    return 0;
}