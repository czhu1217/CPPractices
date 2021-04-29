#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<ll> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
 
#define FOR(i, a, b) for (ll i=a; i<=(b); i++)
#define F0R(i, a) for (ll i=0; i<(a); i++)
#define FORd(i,a,b) for (ll i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (ll i = (a)-1; i >= 0; i--)
 
#define sz(x) (ll)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
const int MM = 105;
int op, n, a[MM*2], b[MM];
int main(){
    cin >> op;
    cin >> n;
    FOR(i, 1, n*2){
        cin >> a[i];
        if(i>n) b[i-n] = a[i];
    }
    ll ans=0;
    if(op==1){
        sort(a+1, a+1+n);
        reverse(a+1, a+1+n);
        sort(b+1, b+1+n);
        reverse(b+1, b+1+n);

        for(int i=1;i<=n;i++){
            ans += max(a[i], b[i]);
        }
    }
    else{
    sort(a+1, a+1+2*n);
    reverse(a+1, a+1+2*n);

        FOR(i, 1, n) ans += a[i];
    }
    cout << ans << "\n";

    return 0;
}