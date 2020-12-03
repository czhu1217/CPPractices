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
int t, a, b, c; int k;
const int mod = 1e9+7;
ll gcd(ll a, ll b) {
   if (b == 0)
   return a;
   return gcd(b, a % b);
}
ll quick_pow(ll x, int exp){
    if(exp==0)return 1;
    ll t = quick_pow(x, exp/2);
    t = t*t%mod;
    return (exp&1)?t*x%mod:t;
}
int main(){
    cin >> t;
    while(t--){
        cin >> a >> b >> c >> k;
        if(a==b) cout << a << "\n";
        else if((b-a)==(c-b)){
            ll dif = b-a;
            a = (a+(dif*(k-1))%mod)%mod;
            cout << a << "\n";
        }
        else if(b/a==c/b){
            ll gc = gcd(a, b);
            ll x = a/gc, y = b/gc;
            x = quick_pow(x, k-1); y = quick_pow(y, k-1);
            a = ((a*y)%mod)/x;
            cout << a << "\n";
        }
    }
    return 0;
}


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
const int MM = 15+5;
pair<int, pair<int, int>> cow[MM];
int n, ans;
deque<pair<int, pair<int, int>>> v;
bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b){
    return a.s.f < b.s.f;
}
int main(){
    //     ifstream cin("convention2.in");
    // ofstream cout("convention2.out");
    memset(cow, 0x3f, sizeof cow);
    cin >> n;
    FOR(i, 1, n){
        cin >> cow[i].first >> cow[i].s.s;
        cow[i].s.f = i;
    }
    sort(cow+1, cow+1+n);
    v.pb(cow[1]); int it = 2; int cur = 0;
    while(!v.empty()){
        pair<int, pi> a = v.front();
        v.pop_front();
        cur = max(a.f, cur+a.s.f);
        ans = max(ans, cur - a.f);
        while(it<=n){
            if(cow[it].f<=cur){
                v.push_back(cow[it]);
                it++;
            }
            else break;
        }
        if(v.empty()&&it<=n){
            v.pb(cow[it]);
            it++;
        } 
        sort(v.begin(), v.end(), cmp);
    }
    cout << ans << "\n";
    return 0;
}