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
ll m, n, sum; const int MM = 1e5+5;
ll a[MM], ans;
int main(){
    cin >> m >> n;
    FOR(i,1,n){
        cin >> a[i];
        sum += a[i];
    }
    ll ave = (sum-m)/n;
    ll rem = (sum-m)%n;
    sort(a+1, a+1+n);
    FOR(i, 1, n){
        if(a[i]>=ave){
            if(!rem){
                ans += ave*ave;
                continue;
            }
            ll t = rem/(n-i+1);
            if(a[i]>=ave+t){
                ans += (ave+t)*(ave+t);
                rem -= t;
            }
            else{
                ans += a[i]*a[i];
                rem -= a[i]-ave;
            }
        }
        else{
            rem += ave-a[i];
            ans += a[i]*a[i];
        }
;    }
    cout << ans << "\n";
    return 0;
}