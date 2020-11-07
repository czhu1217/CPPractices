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
ll n, w, a[1000005], p = 0, ans;
int main(){
    cin >> n >> w; p = n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    for(int i=1;i<=n;i++){
        while(a[i]+a[p]>w&&p>0){
            p--;
        }
        ans += p;
        if(p>=i) ans--;
    }
    cout << ans/2 << "\n";

    return 0;
}