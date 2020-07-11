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
const int MM = 2e6+6;
int n, l; ll dp[MM]; int a[MM];

int main(){
    // cin.tie(0); cin.sync_with_stdio(0);
    memset(dp, 0x3f, sizeof dp);
    cin >> n >> l;
    for(int i=1;i<=n;i++)cin >> a[i];
    dp[0] = 0; int jj=0;
    for(int i=1;i<=n;i++){
        ll sum = a[i]; int temp = 0;
        for(int j=i-1;j>=jj;j--){
            ll tt = dp[i];
            dp[i] = min(dp[i], (ll)pow((sum+i-j-1-l), 2)+dp[j]);
            sum += a[j];
            if(dp[i]!=tt){
                temp = j;
            }
        }
        cout << i <<" "<<temp<<" "<<dp[i]<<"\n";
        jj =temp;
    }
    for(int i=1;i<=n;i++) cout << dp[i] << " ";
    cout << dp[n] << "\n";
    return 0;
}