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
const ll MM = 1e5+5;
ll n, m, l[MM], r[MM], cnt,  a[MM], temp, t;
bool vis[MM]; vector<ll> v;
int main(){
    cin >> n >> m;
    FOR(i, 1, m) cin >> l[i] >> r[i];
    FOR(i, 1, n) a[i] = i;
    FOR(i,1, m){
        temp = a[l[i]];
        a[l[i]]=a[r[i]];
        a[r[i]] = temp;
    }  
    // FOR(i, 1, n) cout << a[i] << "\n";
    // cout << "\n";
    FOR(i, 1, n){
        if(!vis[i]){
            t = 0;
            vis[i] = 1;
            temp = a[i];
            t++;
            while(temp!=i){
                t++;
                vis[temp] = 1;
                temp = a[temp];
            }
            v.pb(t);
        }
    }
    ll lc = 1;
    for(auto e:v){
        lc = lc/__gcd(lc, e)*e;
    }
    cout << lc << "\n";

    return 0;
}