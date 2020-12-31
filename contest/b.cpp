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
const int MM = 1e5+5;
int n, a[MM], b[MM];
void solve(){
    ll ans=0;
    int cur, fu; cur=fu=0;
    cin >> n;
    FOR(i, 1, n){
         cin >> a[i];
    }
    a[n+1] = 0;
    int pt=1, pre=0, pre2=0, cur2=0;
    FOR(i, 1, 2*n+1){
        cur=0; cur2=0;
        while(a[pt]==i){
            cur++;
            pt++;
        }
        if(pre>=1){
            cur2 = pre-1;
            if(pre2) cur2++;
        }
        if(cur||cur2){
            ans++;
        }
        pre = cur;
        pre2 = cur2;
    }
    cout << ans << "\n";


}
int main(){
    int t; cin >> t;
    while(t--)solve();
    return 0;
}