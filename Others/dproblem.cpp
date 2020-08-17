//random number generator, hashing
//nested frequency array
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

#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
const int MM = 1e5+2;
unsigned seedl = chrono::system_clock::now().time_since_epoch().count();
mt19937_64 gen(seedl); uniform_int_distribution<ll> dis(1, 1e12);
int n, m; ll weight[MM], sum, ans, tmp; map<ll, int> mp;
int main(){
    cin >> n >> m;
    FOR(i, 1, m){
        weight[i] = dis(gen);
        sum += weight[i];
    }
    mp[0] = 1;
    FOR(i, 1, n){
        int x; cin >> x;
        tmp += weight[x];
        tmp %= sum;
        ans += mp[tmp]; mp[tmp]++;

    }
    cout << ans << '\n';

    return 0;
}