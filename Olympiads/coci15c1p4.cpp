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
const ll MM = 1e9;
#define f(r, c) ((ll)r*MM+c)
int n, k, p; unordered_map<int, int> xorr, xorc, cntr, cntc; unordered_map<ll, int> g; ll ans;

void ins(int r, int c, int val){
    ans = ans - (n-cntc[xorr[r]]) - (n-cntr[xorc[c]]);
    cntr[xorr[r]]--; cntc[xorc[c]]--;
    xorr[r]^=val; xorc[c]^=val;
    cntr[xorr[r]]++; cntc[xorc[c]]++;
    ans = ans+(n-cntc[xorr[r]])+(n-cntr[xorc[c]]);

}
int main(){
    cin >> n >> k >> p; cntr[0]=cntc[0]=n;
    for(int i=1, r, c, val;i<=k;i++){
        cin >> r >> c >> val;
        ins(r, c, val);
        g[f(r, c)] = val;
    }
    for(int i=1, r1, r2, c1, c2, val;i<=p;i++){
        cin >> r1 >> c1 >> r2 >> c2;
        val = g[f(r1, c1)];
        ins(r1, c1, val); g[f(r1, c1)] = 0;
        ins(r2, c2, val); g[f(r2, c2)] = val;
        cout << ans << "\n";


    }
    return 0;
}