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
ll n, m, p, q, x, y, z, cnt[2], rt[2][MM], mx, mi, dep[2][MM];
struct ed{
    ll a, b, c, i;
    bool operator<(ed &e){
        return c<e.c;
    }
}; vector<ed> v;
ll find(ll x, ll i){
    while(rt[i][x]!=x) x = rt[i][x];
    return x;
}
bool merge( ll a, ll b, ll i)
{
    a = find(a, i), b = find(b, i);
    if (a == b) return 0;
    if (dep[i][a] > dep[i][b])
        rt[i][b] = a;
    else
        rt[i][a] = b;
    if (dep[i][a] == dep[i][b])
        dep[i][b]++;
    return 1;
}
int main(){
    cin >> n >> m >> p >> q;
    FOR(i, 1, m) rt[0][i] = i;
    FOR(i, 1, n) rt[1][i] = i;
    while(p--){
        cin >> x >> y >> z;
        v.pb({x, y, z, 0});
        mx += z*n;
    }
    while(q--){
        cin >> x >> y >> z;
        v.pb({x, y, z, 1});
        mx += z*m;
    }
    sort(v.begin(), v.end());
    for(auto &e:v){
        if(merge(e.a, e.b, e.i)){
            cnt[e.i]++;
            mi += ((e.i?m:n)-cnt[!e.i])*e.c;
        }
    }
    cout << mx -mi << "\n";

    return 0;
}