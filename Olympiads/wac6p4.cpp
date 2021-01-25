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
const int MM = 2e5+5, mod = 998244353;
char ai[MM], b[MM]; ll w, a, c, wa, wac, ac, ans;
int n, k, cnt;
string s;
int main(){
    cin >> n >> k;
    FOR(i, 1, n) cin >> ai[i];
    FOR(i, 1, n){
        if(ai[i]=='W'||ai[i]=='A'||ai[i]=='C'){
            b[++cnt] = ai[i];
        }
    }
    // cout << cnt << "\n";
    FOR(i, 1, n){
        if(b[i]=='W') w++;
        if(b[i]=='A'){
            a++; wa += w;
        }
        if(b[i]=='C'){
            c++; ac += a; wac += wa;
        }
        wa  = wa%mod; ac = ac%mod; wac = wac%mod;
    }
    ans = wac;
    FOR(i, 2, k){
        wac = (wac + (w*ac))%mod;
        wac = (wac+(wa*c)%mod)%mod;
        wac = (wac + ((w*((i-2)*a)%mod)%mod*c)%mod)%mod;
        ans = (ans+wac)%mod;

    }
    cout << ans << "\n";
    return 0;
}