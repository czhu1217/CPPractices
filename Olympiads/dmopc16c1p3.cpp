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
int n; const int MM = 1e4+4;
long double dp[MM], a[MM];
int main(){
    cin >> n;
    FOR(i, 1, n) dp[i] = DBL_MAX;
    FOR(i, 1, n){
        cin >> a[i];
    }
    dp[0] = 0;
    double  b[4], x, y;
    for(int i=1;i<=n;i++){
        dp[i] = dp[i-1]+a[i];
        if(i>1){
            x = a[i-1], y = a[i];
            if(x>y)swap(x, y);
            dp[i] = min(dp[i], dp[i-2]+y+x/2);
        }
        if(i>2){
            b[1] = a[i-2], b[2] = a[i-1], b[3] = a[i];
            sort(b+1, b+4);
            dp[i] = min(dp[i], dp[i-3]+b[2]+b[3]);
        }
    }
printf("%.1Lf\n", dp[n]);

    return 0;
}