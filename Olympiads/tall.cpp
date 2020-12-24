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
const int MM = 2005;
ll n, a[MM], b[MM], ans, c=INT_MAX;
bool m[MM];
int main(){
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n){
        memset(m, 0, sizeof m);
        ll k = a[i];
        // cout << ref << " " << k << "\n";
        FOR(j, 1, n){
            b[j] = a[j]^k;
            if(b[j]<=n) m[b[j]] = 1;
        }
        for(int j=1;j<=n;j++){
            if(!m[j]){
                // cout << j << "\n";
                if(j>ans){
                    ans = j;
                    c = k;
                }
                else if(j==ans){
                    c = min(c, k);
                }
                break;
            }
        }
    }
    cout << ans << " " << c << "\n";

    return 0;
}