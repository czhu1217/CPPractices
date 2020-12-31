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
int w, h, n;
const int MM = 255;
int a[MM][MM], psa[MM][MM], ans;
int main(){
    scanf("%d %d %d", &w, &h, &n);
    FOR(i, 1, h) FOR(j, 1, w) scanf("%d", &a[i][j]);
    FOR(i, 1, h){
        FOR(j, 1, w){
            a[i][j] += a[i-1][j]+a[i][j-1]-a[i-1][j-1];
            FOR(k, 0, j-1){
                int lim = n/(j-k);
                lim = min(lim, i);
                lim = i-lim;
                // cout << i <<  " " << j << " " << k << " " << lim << "\n";
                ans = max(ans, a[i][j]-a[i][k]-a[lim][j]+a[lim][k]);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}