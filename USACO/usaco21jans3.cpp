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
const int MM = 1005;
int n, a[MM][MM]; ll ans, tot;
bool vis[MM][MM];

int main(){
    // ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    FOR(i, 1, n){
        FOR(j, 1, n){
            cin >> a[i][j];
        }
    }
    FOR(i, 1, n){
        ll mx = 0;
        FOR(k, 1, 2){
            ll tmp = 0;
            for(int j=k;j<=n;j+=2){
                tmp += a[i][j];
            }
            mx = max(tmp, mx);
        }
        tot += mx;
    }
    ans = tot;
    tot = 0;

    FOR(i, 1, n){
        ll mx = 0;
        FOR(k, 1, 2){
            ll tmp = 0;
            for(int j=k;j<=n;j+=2){
                tmp += a[j][i];
            }
            mx = max(tmp, mx);
        }
        tot += mx;
    }
    ans = max(ans, tot);
    cout << ans << "\n";
    
    

    return 0;
}