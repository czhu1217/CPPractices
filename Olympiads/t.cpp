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
const int MOD = 1e9+7;
typedef vector<vector<ll>> mat;
ll N, K, T, C, ans; mat a, id;
mat multi(mat x, mat y){
    mat ret(x.size(), vector<ll>(y[0].size(), 0));
    FOR(i, 0, T)
        FOR(k, 0, T)
            FOR(j, 0, T)
                ret[i][j] = (ret[i][j]+x[i][k]*y[k][j])%MOD;
    return ret;
            
}
mat quick_pow(mat m, ll exp){
    if(exp==0) return id;
    mat t = quick_pow(m, exp/2);
    t = multi(t, t);
    if(exp%2==0) return t;
    return multi(t, m);
}
int main(){
    cin >> N >> K >> T >> C;
    a.resize(T+1, vector<ll>(T+1, 0));
    id.resize(T+1, vector<ll>(T+1, 0));
    a[T][T] = 1; a[0][T] = K; id[0][0] = 1;
    for(int i=1;i<=T;i++) a[i][i-1] = 1, id[i][i] = 1;
    a = quick_pow(a, N-1);
    ans = 2*C*a[T][T]%MOD;
    FOR(i, 0, T-1) ans = (ans+1*C*a[i][T]%MOD)%MOD;
    cout << ans << endl;
    return 0;
}