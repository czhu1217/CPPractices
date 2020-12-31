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
int n;
vector<pi> v;
int main(){
    cin >> n;
    int a, b;
    FOR(i, 1, n){
        cin >> a >> b;
        v.pb({a, 1});
        v.pb({b, -1});
    }
    sort(v.begin(), v.end());
    int cnt = 0, ans=0;
    for(auto e:v){
        cnt += e.s;
        ans = max(ans, cnt);
    }
    cout << ans << "\n";
    return 0;
}