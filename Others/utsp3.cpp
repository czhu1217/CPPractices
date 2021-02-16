#include <bits/stdc++.h>
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
const int MM = 1e5+5,mod = 1e9+7;
ll n, a[MM], dp[MM], mx, sum;
int main(){
    dp[0] = 0;
    cin >> n;
    FOR(i, 1, n){
        cin >> a[i];
        if(a[i]<mx){
            dp[i] = dp[i-1];
        }
        else{
            mx = a[i];
            dp[i] = (sum+1)%mod;
        }
        sum = (sum+dp[i])%mod;
    }
    cout << dp[n] << "\n";
    return 0;
}