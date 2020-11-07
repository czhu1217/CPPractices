#include <bits/stdc++.h>
using namespace std; 
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<int,int> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<int> vl;
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
int n, k;
typedef vector<vector<int>> mat;
mat a, id; int ans;
mat multi(mat x, mat y){
    mat ret(x.size(), vector<int>(y[0].size(), 0));
    FOR(i, 0, n)
        FOR(k, 0, n)
            FOR(j, 0, n)
                ret[i][j] = (ret[i][j]+x[i][k]*y[k][j]);
    return ret;
            
}
mat quick_pow(mat m, int exp){
    if(exp==0) return id;
    mat t = quick_pow(m, exp/2);
    t = multi(t, t);
    if(exp%2==0) return t;
    return multi(t, m);
}
int main(){
    cin >> n >> k;
    a.resize(n+1, vector<int>(n+1, 0));
    id.resize(n+1, vector<int>(n+1, 0));
    id[0][0] = 1;
    for(int i=1;i<=n;i++) id[i][i] = 1;
    FOR(i, 1, n){
        FOR(j, 1, n){
            cin >> a[i][j];
        }
    }
    a = quick_pow(a, k);
    FOR(i, 1, n){
        FOR(j, 1, n){
            ans += a[i][j];
        }
    }
    cout << ans << "\n";
    return 0;
}