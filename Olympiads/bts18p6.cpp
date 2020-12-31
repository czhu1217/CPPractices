//prefix difference array
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
ll n, t;
const ll MM = 1e5+5;
ll l, r, a, b, c;
ll con[MM], lin[MM], qua[MM];
int main(){
    scanf("%lld %lld", &n, &t);
    FOR(k, 1, n){
        scanf("%lld %lld %lld %lld %lld", &l, &r, &a, &b, &c);
        if(l+1<=r){
            //quadratic
            qua[l+2] += 2*a; qua[r+1] -= 2*a;
            lin[l+1] += a;lin[r+1] -= (r-l-1)*2*a+a;
            con[r+1] -= a*(r-l)*(r-l);
            //linear
            lin[l+1]+=b; lin[r+1]-=b;
            con[r+1]-=b*(r-l);
        }
        //constant
        con[l]+=c; con[r+1]-=c;
        
    }
    FOR(i, 1, t) qua[i] += qua[i-1];
    FOR(i, 1, t) lin[i] += lin[i-1]+qua[i];
    FOR(i, 1, t) con[i] += con[i-1]+lin[i];
    FOR(i, 1, t) printf("%lld ", con[i]);
    return 0;
}