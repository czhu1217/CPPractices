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
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
ll k;
map<ll, ll> mp;
vector<ll> v;
const int MM = 1e5;
void prime(ll n) 
{ 
    while (n % 2 == 0) 
    { 
        v.pb(2);
        n = n/2; 
    } 
  
    for (ll i = 3; i <= sqrt(n); i = i + 2) 
    { 
        while (n % i == 0) 
        { 
            v.pb(i);
            n = n/i; 
        } 
    } 

    if (n > 2) 
        v.pb(n);
} 
  
int main(){
    cin >> k;
    ll ans = k+1;
    prime(ans);
    // sort(v.begin(), v.end());
    // reverse(v.begin(), v.end());
    ll t;ll cnt = 1;
    // for(auto e:v) cout << e << " ";
    // cout << "\n";
    vector<ll> vi;
    for(auto e:v){
        t = e-1;
        while(t--){
            vi.pb(cnt);
            if(vi.size()>1e5){
            cout << "Sad Chris" << "\n";
            return 0;
        }
        }
        cnt++;

    }
    cout << vi.size() << "\n";
    for(auto e:vi) cout << e << " ";
    cout << "\n";

    return 0;
}