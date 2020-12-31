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
int n, a[55], b[10003];
void solve(){
    memset(b, 0, sizeof b);
    ll ans=0;
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n){
        int temp = 0;
        FOR(j, i+1, n){
            temp += a[j]-a[j-1];
            b[temp]++;
        }
    }
    FOR(i, 1, 10000){
        if(b[i]) ans++;
    }
    cout << ans << "\n";

}

int main(){
    int t; cin >> t;
    while(t--)solve();
    return 0;
}