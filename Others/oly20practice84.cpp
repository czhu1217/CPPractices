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
int r, c,  a[105][105]; 
int dp[105][105][105];
ll ans=0;
int main(){
    memset(dp, 0, sizeof dp);
    cin >> r >> c;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            scanf("%d", &a[i][j]);
        }
    }
    int cnt=0;
    for(int len = c-1;len>0;len--){
        cnt++;
        for(int i=1;i<=r;i++){
            int mx = 0;
            for(int j=1;j+len-1<=c;j++){
                if(j==1){
                    dp[i][j][j+len-1] = dp[i][j][j+len]+cnt*a[i][j+len];
                }
                else if(j+len-1==c){
                    dp[i][j][j+len-1] = dp[i][j-1][j+len-1]+cnt*a[i][j-1];
                }
                else{
                dp[i][j][j+len-1] = max(dp[i][j][j+len]+cnt*a[i][j+len], dp[i][j-1][j+len-1]+cnt*a[i][j-1]);
                }
                if(len==1){
                    mx = max(mx,dp[i][j][j+len-1]+(cnt+1)*a[i][j] );
                }

            }

            ans += mx;
        }
    }
  
    cout << ans << "\n";
    return 0;

}