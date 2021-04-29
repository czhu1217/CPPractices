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
const int MM = 1e5+5;
double k, a[MM];
int n;
int main(){
    cin >> k;
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    double pos = a[1], time = 0;
    FOR(i, 2, n){
        pos += k;
        if(abs(a[i]-pos)<=time){
            continue;
        }
        if(a[i]-pos>time){
            pos -= k;
            double nxt = a[i] - time;
            time += (nxt - pos - k)/2.0;
            pos += k + (nxt - pos - k)/2.0;
        }
        else{
            pos = a[i]+time;
        }

    }
    printf("%.6f\n", time);

    return 0;
}